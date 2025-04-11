/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/04/04 19:00:02 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	set_ray_angle(int ray_index, t_player_data *player)
{
	float	angle_offset;
	float	ray_angle;

	angle_offset = FOV_R * ((float)ray_index / SCREEN_WIDTH - 0.5);
	ray_angle = player->camera_angle_r + angle_offset;
	while (ray_angle < 0)
		ray_angle += 2 * PI;
	while (ray_angle >= 2 * PI)
		ray_angle -= 2 * PI;
	return (ray_angle);
}

int	get_step_x(t_appdata *appdata)
{
	float	ray_dir_x;
	int		step_x;

	ray_dir_x = cos(appdata->raycast->curr_ray);
	if (ray_dir_x == 0)
		appdata->raycast->delta_dist_x = 1e30;
	else
		appdata->raycast->delta_dist_x = fabsf(1 / ray_dir_x);
	if (ray_dir_x < 0)
	{
		step_x = -1;
		appdata->raycast->side_dist_x = (appdata->player->tile_pos_x
				/ TILE_SIZE - appdata->raycast->map_x)
			* appdata->raycast->delta_dist_x;
	}
	else
	{
		step_x = 1;
		appdata->raycast->side_dist_x = (appdata->raycast->map_x
				+ 1.0 - appdata->player->tile_pos_x / TILE_SIZE)
			* appdata->raycast->delta_dist_x;
	}
	return (step_x);
}

int	get_step_y(t_appdata *appdata)
{
	float	ray_dir_y;
	int		step_y;

	ray_dir_y = sin(appdata->raycast->curr_ray);
	appdata->raycast->map_y = (int)(appdata->player->tile_pos_y / TILE_SIZE);
	if (ray_dir_y == 0)
		appdata->raycast->delta_dist_y = 1e30;
	else
		appdata->raycast->delta_dist_y = fabsf(1 / ray_dir_y);
	if (ray_dir_y < 0)
	{
		step_y = -1;
		appdata->raycast->side_dist_y = (appdata->player->tile_pos_y
				/ TILE_SIZE - appdata->raycast->map_y)
			* appdata->raycast->delta_dist_y;
	}
	else
	{
		step_y = 1;
		appdata->raycast->side_dist_y = (appdata->raycast->map_y
				+ 1.0 - appdata->player->tile_pos_y / TILE_SIZE)
			* appdata->raycast->delta_dist_y;
	}
	return (step_y);
}

int	hit_check(t_raycasting *raycast, t_map_data *map, int step_y, int step_x)
{
	int	side;

	while (TRUE)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += step_x;
			side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += step_y;
			side = 1;
		}
		if (raycast->map_y < 0 || raycast->map_x < 0
			|| raycast->map_y >= count_array_len(map->map)
			|| raycast->map_x >= (int)ft_strlen(map->map[raycast->map_y])
			|| map->map[raycast->map_y][raycast->map_x] == '1')
			break ;
	}
	return (side);
}
