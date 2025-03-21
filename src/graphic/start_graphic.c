/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:21:26 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/27 15:41:15 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	get_textures(t_appdata *appdata)
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;

	north = mlx_load_png(appdata->map->n_texture);
	south = mlx_load_png(appdata->map->s_texture);
	west = mlx_load_png(appdata->map->w_texture);
	east = mlx_load_png(appdata->map->e_texture);
	appdata->textures->north = mlx_texture_to_image(appdata->mlx, north);
	appdata->textures->south = mlx_texture_to_image(appdata->mlx, south);
	appdata->textures->west = mlx_texture_to_image(appdata->mlx, west);
	appdata->textures->east = mlx_texture_to_image(appdata->mlx, east);
	if (!appdata->textures->north || !appdata->textures->south
		|| !appdata->textures->west || !appdata->textures->east)
	{
		ft_putstr_fd(TEXTURE_LOADING_ERROR, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
	mlx_delete_texture(north);
	mlx_delete_texture(south);
	mlx_delete_texture(west);
	mlx_delete_texture(east);
}

void draw_the_map(t_appdata *appdata)
{
	int i = 0;
	int j;
	
	while (appdata->map->map[i])
	{
		j = 0;
		while (appdata->map->map[i][j])
		{
			if (appdata->map->map[i][j] == '1')
				mlx_image_to_window(appdata->mlx, appdata->textures->west, j * 64, i * 64);
			if (appdata->map->map[i][j] == '0')
				mlx_image_to_window(appdata->mlx, appdata->textures->north, j * 64, i * 64);
			if (ft_strchr("NSEW", appdata->map->map[i][j]))
				mlx_image_to_window(appdata->mlx, appdata->textures->south, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

//for school screen window size is 640 * 4, 400 * 4
void	init_mlx(t_appdata *appdata)
{
	appdata->mlx = mlx_init(640 * 2, 400 * 2, "cub3D", false);
	if (!appdata->mlx)
	{
		ft_putstr_fd(MLX_ERROR, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
	get_textures(appdata);
	draw_the_map(appdata);
}

void	start_mlx(t_appdata *appdata)
{
	init_mlx(appdata);
	mlx_close_hook(appdata->mlx, &free_after_exit, appdata);
	mlx_key_hook(appdata->mlx, &hook_the_keys, appdata);
	mlx_loop(appdata->mlx);
	mlx_terminate(appdata->mlx);
	free_appdata(appdata);
}
