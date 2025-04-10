/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/10 17:54:59 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_left(t_appdata *appdata, t_player_data *player)
{
	if (!player->is_looking_side)
	{
		player->original_angle = player->camera_angle_d;
		player->camera_angle_d = (player->original_angle - 90 + 360) % 360;
		player->camera_angle_r = deg_to_rad(player->camera_angle_d);
		player->is_looking_side = 1;
		redraw_map(appdata);
	}
}

void	look_right(t_appdata *appdata, t_player_data *player)
{
	if (!player->is_looking_side)
	{
		player->original_angle = player->camera_angle_d;
		player->camera_angle_d = (player->original_angle + 90) % 360;
		player->camera_angle_r = deg_to_rad(player->camera_angle_d);
		player->is_looking_side = 1;
		redraw_map(appdata);
	}
}

void	reset_look(t_appdata *appdata, t_player_data *player)
{
	if (player->is_looking_side)
	{
		player->camera_angle_d = player->original_angle;
		player->camera_angle_r = deg_to_rad(player->camera_angle_d);
		player->is_looking_side = 0;
		redraw_map(appdata);
	}
}
