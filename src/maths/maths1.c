/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/04/04 13:09:30 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	set_ray_angle(int ray_index, t_raycasting *raycast, t_player_data *player)
{
	float	base_angle;
	float	current_ray_angle_rad;
	float	ray_angle_value;

	base_angle = player->camera_position_rad - FOV_R / 2;
	ray_angle_value = ray_index * raycast->angle_btw_rays_rad;
	current_ray_angle_rad = base_angle + ray_angle_value;
	if (current_ray_angle_rad < 0)
		current_ray_angle_rad += 2 * PI;
	if (current_ray_angle_rad >= 2 * PI)
		current_ray_angle_rad -= 2 * PI;
	return (current_ray_angle_rad);
}

float calc_wall_distance(t_appdata *appdata)
{
	float ray_x;
	float ray_y;
	
	ray_x = appdata->player->tile_pos_x;
	ray_y = appdata->player->tile_pos_y;
	float cosr = cos(appdata->raycast->curr_ray_angle) / 1000;
	float sinr = sin(appdata->raycast->curr_ray_angle) / 1000;
    printf("Ray angle: %f radians (%f degrees)\n", appdata->player->camera_position_rad, appdata->player->camera_position_rad * 180 / PI);
    printf("Direction vector: (%f, %f)\n", cos(appdata->player->camera_position_rad), sin(appdata->player->camera_position_rad));
	printf("Ray angle: %f degrees\n", appdata->raycast->curr_ray_angle * 180 / M_PI);
	printf("cosr: %f, sinr: %f\n", cosr, sinr);
	while (is_passable(appdata->map->map, ray_y, ray_x))
	{
		ray_x += cosr;
		ray_y += sinr;
	}
	float ray_dist = sqrt(pow(ray_x - appdata->player->tile_pos_x, 2.0) + pow(ray_y - appdata->player->tile_pos_y, 2.0));
	printf("Final position: (%f, %f)\n", ray_x, ray_y);
    printf("Collision at map position: (%d, %d)\n", 
		(int)(ray_y / 64), (int)(ray_x / 64));
		printf("Distance calculated: %f\n\n", ray_dist);
	return ray_dist;
}
	
float	correct_fishbowl_effect(t_appdata *appdata)
{
	float	corrected_distance;
	float	beta_angle;
	
	beta_angle = fabsf(appdata->raycast->curr_ray_angle - appdata->player->camera_position_rad);
	corrected_distance = appdata->raycast->closest_wall_dist * cos(beta_angle);
	return (corrected_distance);
}

void	wall_height_for_drawing(t_appdata *appdata)
{
	appdata->raycast->projected_slice_height = roundf(TILE_SIZE / appdata->raycast->closest_wall_corrected) * appdata->raycast->dist_to_plane;
	appdata->raycast->slice_starting_point = (SCREEN_HEIGHT / 2) - (appdata->raycast->projected_slice_height / 2);
	appdata->raycast->slice_end_point = appdata->raycast->slice_starting_point + appdata->raycast->projected_slice_height;
}

void	draw_view(t_appdata *appdata, int casted_ray_index, mlx_image_t *img)
{
	int j = 0;
	
	while (j < SCREEN_HEIGHT)
	{
		if (j <= appdata->raycast->slice_starting_point)
		mlx_put_pixel(img, casted_ray_index, j, appdata->textures->ceiling_color);
		else if (j <= appdata->raycast->slice_end_point)
		mlx_put_pixel(img, casted_ray_index, j, 0x00693EFF);
		else
		mlx_put_pixel(img, casted_ray_index, j, appdata->textures->floor_color);
		j++;
	}
}

void	iterate_casted_rays(t_appdata *appdata)
{
	int	casted_ray_index;
	
	appdata->textures->view = mlx_new_image(appdata->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	casted_ray_index = 0;
	printf("Starting position: (%f, %f)\n\n", appdata->player->tile_pos_y, appdata->player->tile_pos_x);
	while (casted_ray_index < SCREEN_WIDTH)
	{
		appdata->raycast->curr_ray_angle = set_ray_angle(casted_ray_index, appdata->raycast, appdata->player);
		appdata->raycast->closest_wall_dist = calc_wall_distance(appdata);
		appdata->raycast->closest_wall_corrected = correct_fishbowl_effect(appdata);
		wall_height_for_drawing(appdata);	
		draw_view(appdata, casted_ray_index, appdata->textures->view);
		casted_ray_index++;
	}
	mlx_image_to_window(appdata->mlx, appdata->textures->view, 0, 0);
}
