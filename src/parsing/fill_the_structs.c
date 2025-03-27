/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:13:56 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/27 17:51:00 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	fill_texture_path(t_map_data *map)
{
	int	i;

	i = -1;
	while (map->whole_map[++i])
	{
		if (ft_strnstr(map->whole_map[i], "NO ", ft_strlen(map->whole_map[i])))
			map->n_texture = get_path(map->whole_map[i]);
		if (ft_strnstr(map->whole_map[i], "SO ", ft_strlen(map->whole_map[i])))
			map->s_texture = get_path(map->whole_map[i]);
		if (ft_strnstr(map->whole_map[i], "WE ", ft_strlen(map->whole_map[i])))
			map->w_texture = get_path(map->whole_map[i]);
		if (ft_strnstr(map->whole_map[i], "EA ", ft_strlen(map->whole_map[i])))
			map->e_texture = get_path(map->whole_map[i]);
	}
	if (!map->n_texture || !map->w_texture
		|| !map->s_texture || !map->e_texture)
		return (ft_putstr_fd(ALLOC_ERROR, 2), FAILURE);
	return (SUCCESS);
}

int	fill_colors(t_map_data *map)
{
	int	i;

	i = -1;
	while (map->whole_map[++i])
	{
		if (ft_strnstr(map->whole_map[i], "F ", ft_strlen(map->whole_map[i])))
			map->floor_colors = get_rgb_colors(map->whole_map[i]);
		if (ft_strnstr(map->whole_map[i], "C ", ft_strlen(map->whole_map[i])))
			map->ceiling_colors = get_rgb_colors(map->whole_map[i]);
	}
	if (!map->ceiling_colors || !map->floor_colors)
		return (FAILURE);
	return (SUCCESS);
}

int	fill_map(t_map_data *map)
{
	map->map = copy_array(map->whole_map, map->map_lines_total);
	if (!map->map)
		return (FAILURE);
	return (SUCCESS);
}

void	fill_player(t_appdata *appdata)
{
	int	y;
	int	x;

	appdata->player->pos_x = find_position(appdata->map->map, 'x');
	appdata->player->pos_y = find_position(appdata->map->map, 'y');
	x = appdata->player->pos_x;
	y = appdata->player->pos_y;
	appdata->player->tile_pos_x = x * 64 + 32;
	appdata->player->tile_pos_y = y * 64 + 32;
	if (appdata->map->map[y][x] == 'E')
		appdata->player->camera_position = 0;
	else if (appdata->map->map[y][x] == 'N')
		appdata->player->camera_position = 90;
	else if (appdata->map->map[y][x] == 'W')
		appdata->player->camera_position = 180;
	else
		appdata->player->camera_position = 270;
	appdata->player->camera_position_rad = deg_to_rad(appdata->player->camera_position);
}

void fill_raycast(t_appdata *appdata)
{
	appdata->raycast->angle_btw_rays_rad = FOV_R / SCREEN_WIDTH;
	appdata->raycast->dist_to_plane = (SCREEN_WIDTH / 2) / tan(FOV_R);
}

int	fill_the_structs(t_appdata *appdata)
{
	if (fill_texture_path(appdata->map) == FAILURE)
	{
		free_appdata(appdata);
		exit(FAILURE);
	}
	if (fill_colors(appdata->map) == FAILURE)
	{
		free_appdata(appdata);
		exit(FAILURE);
	}
	if (fill_map(appdata->map) == FAILURE)
	{
		free_appdata(appdata);
		exit(FAILURE);
	}
	fill_player(appdata);
	fill_raycast(appdata);
	return (SUCCESS);
}
