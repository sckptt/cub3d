/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:21:26 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/14 15:57:34 by vkinsfat         ###   ########.fr       */
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

void	hook_the_keys(mlx_key_data_t keydata, void *param)
{
	t_appdata	*appdata;

	appdata = (t_appdata *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(appdata->mlx);
		free_appdata(appdata);
		exit(SUCCESS);
	}
// 	if (keydata->key == MLX_KEY_W && keydata->action == MLX_PRESS)
// 		// go_forward();
// 	if (keydata->key == MLX_KEY_A && keydata->action == MLX_PRESS)
// 		// go_left();
// 	if (keydata->key == MLX_KEY_S && keydata->action == MLX_PRESS)
// 		// go_back();
// 	if (keydata->key == MLX_KEY_D && keydata->action == MLX_PRESS)
// 		// go_right();
// 	if (keydata->key == MLX_KEY_LEFT && keydata->action == MLX_PRESS)
// 		//turn_left();
// 	if (keydata->key == MLX_KEY_RIGHT && keydata->action == MLX_PRESS)
// 		//turn_right();
}

void	init_mlx(t_appdata *appdata)
{
	appdata->mlx = mlx_init(640 * 4, 400 * 4, "cub3D", false);
	if (!appdata->mlx)
	{
		ft_putstr_fd(MLX_ERROR, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
// 	get_textures(appdata);
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
