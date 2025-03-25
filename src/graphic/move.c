/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/24 19:13:00 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void redraw_map(t_appdata *appdata)
{
	if (appdata->textures->player)
		mlx_delete_image(appdata->mlx, appdata->textures->player);
	draw_player_square(appdata);
}

void move_player(t_appdata *appdata, int offset)
{
	double	x;
	double	y;
	double	angle;
	int new_angle;

	new_angle = (appdata->player->camera_position + offset) % 360;
	angle = deg_to_rad(new_angle);
	y = appdata->player->tile_pos_y + sin(angle) * appdata->player->move_speed;
	x = appdata->player->tile_pos_x + cos(angle) * appdata->player->move_speed;
	if (!is_passable(appdata->map->map, y, x))
		return ;
	appdata->player->tile_pos_y = y;
	appdata->player->tile_pos_x = x;
	redraw_map(appdata);
}

void	hook_the_keys(mlx_key_data_t keydata, void *param)
{
	t_appdata	*appdata;

	appdata = (t_appdata *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(appdata->mlx);
		free_appdata(appdata);
		exit(SUCCESS);
	}
	if (mlx_is_key_down(appdata->mlx, MLX_KEY_W))
		move_player(appdata, 0);
	if (mlx_is_key_down(appdata->mlx, MLX_KEY_S))
		move_player(appdata, 180);
	if (mlx_is_key_down(appdata->mlx, MLX_KEY_A))
		move_player(appdata, 270);
	if (mlx_is_key_down(appdata->mlx, MLX_KEY_D))
		move_player(appdata, 90);
	if (mlx_is_key_down(appdata->mlx, MLX_KEY_LEFT))
		turn_left(appdata->player);
	if (mlx_is_key_down(appdata->mlx, MLX_KEY_RIGHT))
		turn_right(appdata->player);
}
