/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:21:26 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/04/10 17:55:36 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_png(t_appdata *appdata)
{
	appdata->textures->north_texture = mlx_load_png(appdata->map->n_texture);
	appdata->textures->south_texture = mlx_load_png(appdata->map->s_texture);
	appdata->textures->east_texture = mlx_load_png(appdata->map->e_texture);
	appdata->textures->west_texture = mlx_load_png(appdata->map->w_texture);
	if (!appdata->textures->north_texture || !appdata->textures->south_texture
		|| !appdata->textures->east_texture || !appdata->textures->west_texture)
	{
		ft_putstr_fd(NON_EXISTING_TEXTURE, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
}

void	get_textures(t_appdata *appdata)
{
	load_png(appdata);
	appdata->textures->north = mlx_texture_to_image(appdata->mlx,
			appdata->textures->north_texture);
	appdata->textures->south = mlx_texture_to_image(appdata->mlx,
			appdata->textures->south_texture);
	appdata->textures->east = mlx_texture_to_image(appdata->mlx,
			appdata->textures->east_texture);
	appdata->textures->west = mlx_texture_to_image(appdata->mlx,
			appdata->textures->west_texture);
	if (!appdata->textures->north || !appdata->textures->south
		|| !appdata->textures->west || !appdata->textures->east)
	{
		ft_putstr_fd(TEXTURE_LOADING_ERROR, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
}

void	init_mlx(t_appdata *appdata)
{
	appdata->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", false);
	if (!appdata->mlx)
	{
		ft_putstr_fd(MLX_ERROR, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
	get_textures(appdata);
	iterate_casted_rays(appdata);
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
