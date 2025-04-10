/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/04/10 15:42:16 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//THIS WHOLE FILE AND ALL ITS FUNCTIONS HAVE BEEN ADDED TO HANDLE TEXTURES

void    calculate_wall_hit_position(t_appdata *appdata)
{
	t_raycasting *raycast = appdata->raycast;
	
	if (raycast->wall_side == 0) // If hit vertical wall
		raycast->wall_x = appdata->player->tile_pos_y / TILE_SIZE + 
			raycast->wall_dist * sin(raycast->curr_ray) / TILE_SIZE;
	else // If hit horizontal wall
		raycast->wall_x = appdata->player->tile_pos_x / TILE_SIZE + 
			raycast->wall_dist * cos(raycast->curr_ray) / TILE_SIZE;
	
	raycast->wall_x -= floor(raycast->wall_x); // Get fractional part
}

mlx_image_t *get_texture_for_side(t_appdata *appdata)
{
	t_raycasting *raycast = appdata->raycast;
	float ray_angle = raycast->curr_ray;
	
	if (raycast->wall_side == 1) // Horizontal hit (North/South)
	{
		if (sin(ray_angle) > 0) // Ray facing down (South)
			return appdata->textures->south;
		else // Ray facing up (North)
			return appdata->textures->north;
	}
	else // Vertical hit (East/West)
	{
		if (cos(ray_angle) > 0) // Ray facing right (East)
			return appdata->textures->east;
		else // Ray facing left (West)
			return appdata->textures->west;
	}
}

void    calculate_texture_x(t_appdata *appdata, mlx_image_t *texture)
{
	t_raycasting *raycast = appdata->raycast;
	
	// Calculate x coordinate on the texture
	int tex_width = texture->width;
	raycast->tex_x = (int)(raycast->wall_x * tex_width);
	
	// Flip texture x coordinate for certain walls to maintain consistency
	if ((raycast->wall_side == 0 && cos(raycast->curr_ray) > 0) ||
		(raycast->wall_side == 1 && sin(raycast->curr_ray) < 0))
		raycast->tex_x = tex_width - raycast->tex_x - 1;
}

void    draw_textured_wall_slice(t_appdata *appdata, int ray_index)
{
	t_raycasting *raycast = appdata->raycast;
	mlx_image_t *texture = get_texture_for_side(appdata);
	int y, color;
	
	calculate_texture_x(appdata, texture);
	
	// Calculate how much to increase the texture coordinate per screen pixel
	float step = (float)texture->height / raycast->slice_height;
	// Starting texture position
	float tex_pos = (raycast->wall_start - SCREEN_HEIGHT / 2 + 
					raycast->slice_height / 2) * step;
	
	y = raycast->wall_start;
	while (y < raycast->wall_end)
	{
		// Cast to int for texture lookup
		raycast->tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		
		// Get pixel color from texture
		uint8_t *pixel = (uint8_t *)texture->pixels + 
					(raycast->tex_y * texture->width + raycast->tex_x) * 4;
		
		color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3];
		mlx_put_pixel(appdata->textures->view, ray_index, y, color);
		y++;
	}
}

void    draw_ceiling_and_floor(t_appdata *appdata, int ray_index)
{
	t_raycasting *raycast = appdata->raycast;
	int y = 0;
	
	// Draw ceiling
	while (y < raycast->wall_start)
	{
		mlx_put_pixel(appdata->textures->view, ray_index, y, 
					appdata->textures->ceil_rgba);
		y++;
	}
	
	// Draw floor
	y = raycast->wall_end;
	while (y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(appdata->textures->view, ray_index, y, 
					appdata->textures->floor_rgba);
		y++;
	}
}