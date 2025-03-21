/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:29 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/21 15:52:58 by vitakinsfat      ###   ########.fr       */
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
	appdata->map->n_texture = NULL;
	appdata->map->s_texture = NULL;
	appdata->map->w_texture = NULL;
	appdata->map->e_texture = NULL;
	appdata->map->floor_colors = NULL;
	appdata->map->ceiling_colors = NULL;
	appdata->map->map_lines_total = 0;
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
	appdata->textures->ceiling_color = 0;
	appdata->textures->floor_color = 0;
}

void	init_appdata(t_appdata *appdata)
{
	appdata->map = NULL;
	appdata->player = NULL;
	appdata->textures = NULL;
	appdata->mlx = NULL;
	init_map_data(appdata);
	init_player_data(appdata);
	init_textures(appdata);
}
