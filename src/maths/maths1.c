/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_username <your_email@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:00:00 by your_username    #+#    #+#             */
/*   Updated: 2025/04/04 15:30:00 by your_username   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calc_wall_distance_dda(t_appdata *appdata)
{
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	ray_dir_x = cos(appdata->raycast->curr_ray);
	ray_dir_y = sin(appdata->raycast->curr_ray);
	map_x = (int)(appdata->player->tile_pos_x / TILE_SIZE);
	map_y = (int)(appdata->player->tile_pos_y / TILE_SIZE);
	delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
	delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);
	hit = 0;
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (appdata->player->tile_pos_x / TILE_SIZE - map_x)
			* delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - appdata->player->tile_pos_x / TILE_SIZE)
			* delta_dist_x;
	}
	
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (appdata->player->tile_pos_y / TILE_SIZE - map_y)
			* delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - appdata->player->tile_pos_y / TILE_SIZE)
			* delta_dist_y;
	}
	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (map_y < 0 || map_x < 0
			|| map_y >= count_array_len(appdata->map->map)
			|| map_x >= (int)ft_strlen(appdata->map->map[map_y])
			|| appdata->map->map[map_y][map_x] == '1')
		{
			hit = 1;
		}
	}
	if (side == 0)
		perp_wall_dist = (side_dist_x - delta_dist_x);
	else
		perp_wall_dist = (side_dist_y - delta_dist_y);
	perp_wall_dist *= TILE_SIZE;
	appdata->raycast->wall_side = side;
	return (perp_wall_dist);
}

float	correct_fishbowl_effect(t_appdata *appdata)
{
	float	corrected_distance;
	float	beta_angle;

	beta_angle = fabsf(appdata->raycast->curr_ray
			- appdata->player->camera_angle_r);
	if (beta_angle > PI)
		beta_angle = 2 * PI - beta_angle;
	corrected_distance = appdata->raycast->wall_dist * cos(beta_angle);
	return (corrected_distance);
}

void	wall_height_for_drawing(t_raycasting *raycast)
{
	float	wall_height;

	wall_height = (float)TILE_SIZE / raycast->correct_dist
		* raycast->dist_to_plane;
	raycast->slice_height = (int)fmax(1, wall_height);
	raycast->wall_start = (SCREEN_HEIGHT - raycast->slice_height) / 2;
	raycast->wall_end = raycast->wall_start + raycast->slice_height;
	if (raycast->wall_start < 0)
		raycast->wall_start = 0;
	if (raycast->wall_end >= SCREEN_HEIGHT)
		raycast->wall_end = SCREEN_HEIGHT - 1;
}

void	draw_the_picture(t_appdata *appdata, int ray_index)
{
	uint32_t	color;
	int			y;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < appdata->raycast->wall_start)
			color = appdata->textures->ceil_rgba;
		else if (y <= appdata->raycast->wall_end)
		{
			if (appdata->raycast->wall_side == 0)
				color = 0x00693EFF;
			else
				color = 0x004D2EFF;
		}
		else
			color = appdata->textures->floor_rgba;
		mlx_put_pixel(appdata->textures->view, ray_index, y, color);
	}
}

void	iterate_casted_rays(t_appdata *appdata)
{
	int	ray_index;

	appdata->textures->view = mlx_new_image(appdata->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	ray_index = -1;
	if (!appdata->textures->view)
	{
		ft_putstr_fd("Error creating view image\n", 2);
		return ;
	}
	while (++ray_index < SCREEN_WIDTH)
	{
		appdata->raycast->curr_ray = set_ray_angle(ray_index, appdata->player);
		appdata->raycast->wall_dist = calc_wall_distance_dda(appdata);
		appdata->raycast->correct_dist = correct_fishbowl_effect(appdata);
		wall_height_for_drawing(appdata->raycast);
		draw_the_picture(appdata, ray_index);
	}
	mlx_image_to_window(appdata->mlx, appdata->textures->view, 0, 0);
}
