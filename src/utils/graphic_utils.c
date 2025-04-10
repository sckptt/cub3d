/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:21:28 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/04/10 18:16:00 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	rgb_to_long(int *rgb_array)
{
	if (!rgb_array)
		return (0);
	return (rgb_array[0] << 24 | rgb_array[1] << 16 | rgb_array[2] << 8 | 0xFF);
}

mlx_image_t	*get_texture_for_side(t_appdata *appdata)
{
	t_raycasting	*raycast;
	float			ray_angle;

	raycast = appdata->raycast;
	ray_angle = raycast->curr_ray;
	if (raycast->wall_side == 1)
	{
		if (sin(ray_angle) > 0)
			return (appdata->textures->south);
		else
			return (appdata->textures->north);
	}
	else
	{
		if (cos(ray_angle) > 0)
			return (appdata->textures->east);
		else
			return (appdata->textures->west);
	}
}
