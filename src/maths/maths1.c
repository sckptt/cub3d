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
	float	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;

	appdata->raycast->map_x = (int)(appdata->player->tile_pos_x / TILE_SIZE);
	appdata->raycast->map_y = (int)(appdata->player->tile_pos_y / TILE_SIZE);
	step_x = get_step_x(appdata);
	step_y = get_step_y(appdata);
	side = hit_check(appdata->raycast, appdata->map, step_y, step_x);
	if (side == 0)
		perp_wall_dist = (appdata->raycast->side_dist_x
				- appdata->raycast->delta_dist_x);
	else
		perp_wall_dist = (appdata->raycast->side_dist_y
				- appdata->raycast->delta_dist_y);
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

//ADDED FOR HANDLING TEXTURES (remplacing the old one commented out below):
void draw_the_picture(t_appdata *appdata, int ray_index)
{
    // Draw ceiling and floor
    draw_ceiling_and_floor(appdata, ray_index);
    
    // Calculate exact point where wall was hit
    calculate_wall_hit_position(appdata);
    
    // Draw the textured wall slice
    draw_textured_wall_slice(appdata, ray_index);
}

// void	draw_the_picture(t_appdata *appdata, int ray_index)
// {
// 	uint32_t	color;
// 	int			y;

// 	y = -1;
// 	while (++y < SCREEN_HEIGHT)
// 	{
// 		if (y < appdata->raycast->wall_start)
// 			color = appdata->textures->ceil_rgba;
// 		else if (y <= appdata->raycast->wall_end)
// 		{
// 			if (appdata->raycast->wall_side == 0)
// 				color = 0x00693EFF;
// 			else
// 				color = 0x004D2EFF;
// 		}
// 		else
// 			color = appdata->textures->floor_rgba;
// 		mlx_put_pixel(appdata->textures->view, ray_index, y, color);
// 	}
// }

void	iterate_casted_rays(t_appdata *appdata)
{
	int	ray_index;

	appdata->textures->view = mlx_new_image(appdata->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	ray_index = -1;
	if (!appdata->textures->view)
	{
		ft_putstr_fd(IMAGE_CREATION_ERROR, 2);
		free_appdata(appdata);
		exit(FAILURE);
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
