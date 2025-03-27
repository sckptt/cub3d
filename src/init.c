/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:29 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/27 17:23:46 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map_data(t_appdata *appdata)
{
	appdata->map = malloc(sizeof(t_map_data));
	if (!appdata->map)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		exit(FAILURE);
	}
	appdata->map->whole_map = NULL;
	appdata->map->map = NULL;
	appdata->map->copy_map = NULL;
	appdata->map->n_texture = NULL;
	appdata->map->s_texture = NULL;
	appdata->map->w_texture = NULL;
	appdata->map->e_texture = NULL;
	appdata->map->floor_colors = NULL;
	appdata->map->ceiling_colors = NULL;
	appdata->map->row_len = NULL;
	appdata->map->map_lines_total = 0;
	appdata->map->unit_size = 64;
}

static void	init_player_data(t_appdata *appdata)
{
	appdata->player = malloc(sizeof(t_player_data));
	if (!appdata->player)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		free(appdata->map);
		exit(FAILURE);
	}
	appdata->player->pos_x = 0;
	appdata->player->pos_y = 0;
	appdata->player->camera_position = 0;
	appdata->player->tile_pos_x = 0;
	appdata->player->tile_pos_y = 0;
	appdata->player->move_speed = 10;
	appdata->player->turn_speed = 30;
	appdata->player->field_of_view_deg = 0;
	appdata->player->field_of_view_rad = 0;
	appdata->player->eyes_height = appdata->map->unit_size / 2;
	appdata->player->camera_position_rad = 0;
}

static void	init_textures(t_appdata *appdata)
{
	appdata->textures = malloc(sizeof(t_textures));
	if (!appdata->textures)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		free(appdata->map);
		free(appdata->player);
		exit(FAILURE);
	}
	appdata->textures->north = NULL;
	appdata->textures->south = NULL;
	appdata->textures->west = NULL;
	appdata->textures->east = NULL;
	appdata->textures->player = NULL; //temp
	appdata->textures->ceiling_color = 0;
	appdata->textures->floor_color = 0;
}

static void	init_raycast(t_appdata *appdata)
{
	appdata->raycast = malloc(sizeof(t_textures));
	if (!appdata->raycast)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		free(appdata->map);
		free(appdata->player);
		free(appdata->textures);
		exit(FAILURE);
	}
	appdata->raycast->angle_btw_rays_rad = 0;
	appdata->raycast->dist_to_plane = 0;
	appdata->raycast->curr_ray_angle = 0;
	appdata->raycast->closest_wall_dist = 0;
	appdata->raycast->closest_wall_corrected = 0;
	appdata->raycast->first_h_intersection_coord_x = 0;
	appdata->raycast->first_h_intersection_coord_y = 0;
	appdata->raycast->next_h_intersection_coord_x = 0;
	appdata->raycast->next_h_intersection_coord_y = 0;
	appdata->raycast->first_v_intersection_coord_x = 0;
	appdata->raycast->first_v_intersection_coord_y = 0;
	appdata->raycast->next_v_intersection_coord_x = 0;
	appdata->raycast->next_v_intersection_coord_y = 0;
	appdata->raycast->projected_slice_height = 0;
	appdata->raycast->slice_starting_point = 0;
	appdata->raycast->slice_end_point = 0;
}

void	init_appdata(t_appdata *appdata)
{
	appdata->map = NULL;
	appdata->player = NULL;
	appdata->textures = NULL;
	appdata->mlx = NULL;
	appdata->raycast = NULL;
	init_map_data(appdata);
	init_player_data(appdata);
	init_textures(appdata);
	init_raycast(appdata);
}
