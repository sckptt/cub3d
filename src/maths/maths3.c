/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/04/10 18:16:55 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_hit_position(t_appdata *appdata)
{
	t_raycasting	*raycast;

	raycast = appdata->raycast;
	if (raycast->wall_side == 0)
		raycast->wall_x = appdata->player->tile_pos_y / TILE_SIZE
			+ raycast->wall_dist * sin(raycast->curr_ray) / TILE_SIZE;
	else
		raycast->wall_x = appdata->player->tile_pos_x / TILE_SIZE
			+ raycast->wall_dist * cos(raycast->curr_ray) / TILE_SIZE;
	raycast->wall_x -= floor(raycast->wall_x);
}

void	calculate_texture_x(t_appdata *appdata, mlx_image_t *texture)
{
	t_raycasting	*raycast;
	int				tex_width;

	raycast = appdata->raycast;
	tex_width = texture->width;
	raycast->tex_x = (int)(raycast->wall_x * tex_width);
	if ((raycast->wall_side == 0 && cos(raycast->curr_ray) > 0)
		|| (raycast->wall_side == 1 && sin(raycast->curr_ray) < 0))
		raycast->tex_x = tex_width - raycast->tex_x - 1;
}

void	get_color_and_draw(t_appdata *appdata,
	mlx_image_t *texture, int ray_index)
{
	int		y;
	int		color;
	uint8_t	*pixel;
	float	step;
	float	tex_pos;

	y = appdata->raycast->wall_start;
	step = (float)texture->height / appdata->raycast->slice_height;
	tex_pos = (appdata->raycast->wall_start - SCREEN_HEIGHT / 2
			+ appdata->raycast->slice_height / 2) * step;
	while (y < appdata->raycast->wall_end)
	{
		appdata->raycast->tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		pixel = (uint8_t *)texture->pixels
			+ (appdata->raycast->tex_y * texture->width
				+ appdata->raycast->tex_x) * 4;
		color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8)
			| pixel[3];
		mlx_put_pixel(appdata->textures->view, ray_index, y, color);
		y++;
	}
}

void	draw_textured_wall_slice(t_appdata *appdata, int ray_index)
{
	mlx_image_t		*texture;

	texture = get_texture_for_side(appdata);
	calculate_texture_x(appdata, texture);
	get_color_and_draw(appdata, texture, ray_index);
}

void	draw_ceiling_and_floor(t_appdata *appdata, int ray_index)
{
	t_raycasting	*raycast;
	int				y;

	raycast = appdata->raycast;
	y = 0;
	while (y < raycast->wall_start)
	{
		mlx_put_pixel(appdata->textures->view, ray_index, y,
			appdata->textures->ceil_rgba);
		y++;
	}
	y = raycast->wall_end;
	while (y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(appdata->textures->view, ray_index, y,
			appdata->textures->floor_rgba);
		y++;
	}
}
