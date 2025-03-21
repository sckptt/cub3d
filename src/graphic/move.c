/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/21 22:28:18 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_forward(t_appdata *appdata)
{
	double	x;
	double	y;
	double	angle;

	printf("W pressed! Go forward\n");
	angle = deg_to_rad(appdata->player->camera_position);
	y = appdata->player->tile_pos_y + sin(angle) * appdata->player->move_speed;
	x = appdata->player->tile_pos_x + cos(angle) * appdata->player->move_speed;
	printf("Y is %f\nX is %f\n\n", y, x);
	if (!is_passable(appdata->map->map, y, x))
		return ;
	appdata->player->tile_pos_y = y;
	appdata->player->tile_pos_x = x;
}

void	go_back(t_appdata *appdata)
{
	double	x;
	double	y;
	double	angle;

	printf("S pressed! Go back\n");
	angle = deg_to_rad(appdata->player->camera_position);
	y = appdata->player->tile_pos_y - sin(angle) * appdata->player->move_speed;
	x = appdata->player->tile_pos_x - cos(angle) * appdata->player->move_speed;
	printf("Y is %f\nX is %f\n\n", y, x);
	if (!is_passable(appdata->map->map, y, x))
		return ;
	appdata->player->tile_pos_y = y;
	appdata->player->tile_pos_x = x;
}

void	go_left(t_appdata *appdata)
{
	double	x;
	double	y;
	double	angle;
	int		camera_pos;

	printf("A pressed! Go left\n");
	camera_pos = (appdata->player->camera_position + 270) % 360;
	angle = deg_to_rad(camera_pos);
	y = appdata->player->tile_pos_y + sin(angle) * appdata->player->move_speed;
	x = appdata->player->tile_pos_x + cos(angle) * appdata->player->move_speed;
	printf("Y is %f\nX is %f\n\n", y, x);
	if (!is_passable(appdata->map->map, y, x))
		return ;
	appdata->player->tile_pos_y = y;
	appdata->player->tile_pos_x = x;
}

void	go_right(t_appdata *appdata)
{
	double	x;
	double	y;
	double	angle;
	int		camera_pos;

	printf("D pressed! Go right\n");
	camera_pos = (appdata->player->camera_position + 90) % 360;
	angle = deg_to_rad(camera_pos);
	y = appdata->player->tile_pos_y + sin(angle) * appdata->player->move_speed;
	x = appdata->player->tile_pos_x + cos(angle) * appdata->player->move_speed;
	printf("Y is %f\nX is %f\n\n", y, x);
	if (!is_passable(appdata->map->map, y, x))
		return ;
	appdata->player->tile_pos_y = y;
	appdata->player->tile_pos_x = x;
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
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		go_forward(appdata);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		go_back(appdata);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		go_left(appdata);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		go_right(appdata);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		turn_left(appdata->player);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		turn_right(appdata->player);
}
