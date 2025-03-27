/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:50:21 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/14 16:27:51 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

static void	free_map_data(t_map_data *map)
{
	if (map->whole_map)
		free_char_array(map->whole_map);
	if (map->map)
		free_char_array(map->map);
	if (map->n_texture)
		free(map->n_texture);
	if (map->s_texture)
		free(map->s_texture);
	if (map->w_texture)
		free(map->w_texture);
	if (map->e_texture)
		free(map->e_texture);
	if (map->floor_colors != 0)
		free(map->floor_colors);
	if (map->ceiling_colors != 0)
		free(map->ceiling_colors);
	free(map);
}

static void free_textures(t_appdata *appdata)
{
	if (appdata->textures->north)
		mlx_delete_image(appdata->mlx, appdata->textures->north);
	if (appdata->textures->south)
		mlx_delete_image(appdata->mlx, appdata->textures->south);
	if (appdata->textures->west)
		mlx_delete_image(appdata->mlx, appdata->textures->west);
	if (appdata->textures->east)
		mlx_delete_image(appdata->mlx, appdata->textures->east);
	free(appdata->textures);
}

void	free_appdata(t_appdata *appdata)
{
	if (appdata->map)
		free_map_data(appdata->map);
	if (appdata->player)
		free(appdata->player);
// added by Y:
	if (appdata->raycast)
		free(appdata->raycast);

	if (appdata->mlx)
	{
		if (appdata->textures)
			free_textures(appdata);
		mlx_terminate(appdata->mlx);	
	}
}

void	free_after_exit(void *param)
{
	t_appdata	*appdata;

	appdata = (t_appdata *)param;
	free_appdata(appdata);
	exit(SUCCESS);
}
