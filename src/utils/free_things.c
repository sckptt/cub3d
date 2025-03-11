/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:50:21 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/10 17:32:55 by vkinsfat         ###   ########.fr       */
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

void free_map_data(t_appdata *appdata)
{
	if (appdata->map->whole_map != NULL)
		free_char_array(appdata->map->whole_map);
	if (appdata->map->map != NULL)
		free_char_array(appdata->map->map);
	if (appdata->map->n_texture != NULL)
		free(appdata->map->n_texture);
	if (appdata->map->s_texture != NULL)
		free(appdata->map->s_texture);
	if (appdata->map->w_texture != NULL)
		free(appdata->map->w_texture);
	if (appdata->map->e_texture != NULL)
		free(appdata->map->e_texture);
	if (appdata->map->floor_colors != 0)
		free(appdata->map->floor_colors);
	if (appdata->map->ceiling_colors != 0)
		free(appdata->map->ceiling_colors);
	free(appdata->map);
}

void	free_appdata(t_appdata *appdata)
{
	free_map_data(appdata);
	// free(appdata->player);
	// free(appdata->textures);
}
