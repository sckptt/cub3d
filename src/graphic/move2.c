/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/04 16:26:23 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_left(t_appdata *appdata)
{
	if (!appdata->player->is_looking_side)
	{
		appdata->player->original_angle = appdata->player->camera_angle_d;
		appdata->player->camera_angle_d = (appdata->player->original_angle - 90 + 360) % 360;
		appdata->player->camera_angle_r = deg_to_rad(appdata->player->camera_angle_d);
		appdata->player->is_looking_side = 1;
		redraw_map(appdata);
	}
}

void	look_right(t_appdata *appdata)
{
	if (!appdata->player->is_looking_side)
	{
		appdata->player->original_angle = appdata->player->camera_angle_d;
		appdata->player->camera_angle_d = (appdata->player->original_angle + 90) % 360;
		appdata->player->camera_angle_r = deg_to_rad(appdata->player->camera_angle_d);
		appdata->player->is_looking_side = 1;
		redraw_map(appdata);
	}
}

void	reset_look(t_appdata *appdata)
{
	if (appdata->player->is_looking_side)
	{
		appdata->player->camera_angle_d = appdata->player->original_angle;
		appdata->player->camera_angle_r = deg_to_rad(appdata->player->camera_angle_d);
		appdata->player->is_looking_side = 0;
		redraw_map(appdata);
	}
}