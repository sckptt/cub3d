/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/10 17:54:14 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	redraw_map(t_appdata *appdata)
{
	if (appdata->textures->view)
		mlx_delete_image(appdata->mlx, appdata->textures->view);
	iterate_casted_rays(appdata);
}

void	turn_left(t_appdata *appdata, t_player_data *player)
{
	player->camera_angle_d = (player->camera_angle_d - TURN_SPEED + 360) % 360;
	player->camera_angle_r = deg_to_rad(player->camera_angle_d);
	redraw_map(appdata);
}

void	turn_right(t_appdata *appdata, t_player_data *player)
{
	player->camera_angle_d = (player->camera_angle_d + TURN_SPEED) % 360;
	player->camera_angle_r = deg_to_rad(player->camera_angle_d);
	redraw_map(appdata);
}

void	move_player(t_appdata *appdata, int offset)
{
	double	x;
	double	y;
	double	angle;
	int		new_angle;

	new_angle = (appdata->player->camera_angle_d + offset) % 360;
	angle = deg_to_rad(new_angle);
	y = appdata->player->tile_pos_y + sin(angle) * MOVE_SPEED;
	x = appdata->player->tile_pos_x + cos(angle) * MOVE_SPEED;
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
		turn_left(appdata, appdata->player);
	if (mlx_is_key_down(appdata->mlx, MLX_KEY_D))
		turn_right(appdata, appdata->player);
	if (mlx_is_key_down(appdata->mlx, MLX_KEY_LEFT))
		look_left(appdata, appdata->player);
	else if (mlx_is_key_down(appdata->mlx, MLX_KEY_RIGHT))
		look_right(appdata, appdata->player);
	else if (appdata->player->is_looking_side)
		reset_look(appdata, appdata->player);
}

//FUNCTION MODIFIED TO ONLY CORRECT THE BEHAVIOR of A and D keys, newer above^^
// void	hook_the_keys(mlx_key_data_t keydata, void *param)
// {
// 	t_appdata	*appdata;

// 	appdata = (t_appdata *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 	{
// 		mlx_close_window(appdata->mlx);
// 		free_appdata(appdata);
// 		exit(SUCCESS);
// 	}
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_W))
// 		move_player(appdata, 0);
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_S))
// 		move_player(appdata, 180);
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_A))
// 		turn_left(appdata, appdata->player);
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_D))
// 		turn_right(appdata, appdata->player);
// }

//OLD FUNCTION, see newer just above
// void	hook_the_keys(mlx_key_data_t keydata, void *param)
// {
// 	t_appdata	*appdata;

// 	appdata = (t_appdata *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 	{
// 		mlx_close_window(appdata->mlx);
// 		free_appdata(appdata);
// 		exit(SUCCESS);
// 	}
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_W))
// 		move_player(appdata, 0);
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_S))
// 		move_player(appdata, 180);
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_A))
// 		move_player(appdata, 270);
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_D))
// 		move_player(appdata, 90);
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_LEFT))
// 		turn_left(appdata, appdata->player);
// 	if (mlx_is_key_down(appdata->mlx, MLX_KEY_RIGHT))
// 		turn_right(appdata, appdata->player);
// }
