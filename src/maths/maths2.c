/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/04/04 17:37:50 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	set_ray_angle(int ray_index, t_player_data *player)
{
	float	ray_angle;
	float	angle_offset;

	angle_offset = FOV_R * ((float)ray_index / SCREEN_WIDTH - 0.5);
	ray_angle = player->camera_angle_r + angle_offset;
	while (ray_angle < 0)
		ray_angle += 2 * PI;
	while (ray_angle >= 2 * PI)
		ray_angle -= 2 * PI;
	return (ray_angle);
}

float	calc_wall_distance_basic(t_appdata *appdata)
{
	float	ray_x;
	float	ray_y;
	float	ray_dir_x;
	float	ray_dir_y;
	float	ray_dist;

	ray_x = appdata->player->tile_pos_x;
	ray_y = appdata->player->tile_pos_y;
	ray_dir_x = cos(appdata->raycast->curr_ray);
	ray_dir_y = sin(appdata->raycast->curr_ray);
	while (is_passable(appdata->map->map, ray_y, ray_x))
	{
		ray_x += ray_dir_x * 0.1;
		ray_y += ray_dir_y * 0.1;
	}
	ray_dist = sqrt(pow(ray_x - appdata->player->tile_pos_x, 2.0)
			+ pow(ray_y - appdata->player->tile_pos_y, 2.0));
	return (ray_dist);
}
