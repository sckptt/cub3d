/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:23:29 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/10 17:29:34 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_map_data(t_appdata *appdata)
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
	appdata->map->floor_colors = 0;
	appdata->map->ceiling_colors = 0;
	appdata->map->map_lines_total = 0;
}

void init_player_data(t_appdata *appdata)
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
}

void init_textures(t_appdata *appdata)
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
}

void init_appdata(t_appdata *appdata)
{
	appdata->map = NULL;
	appdata->player = NULL;
	appdata->textures = NULL;
	//appdata->mlx = NULL;
	init_map_data(appdata);
	init_player_data(appdata);
	init_textures(appdata);
}
