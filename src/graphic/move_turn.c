/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/21 17:28:28 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void turn_left(t_player_data *player)
{
	int new_position;

	new_position = player->camera_position + player->turn_speed;
	if (new_position > 360)
	{
		new_position = player->turn_speed - 360 + player->camera_position;
		player->camera_position = new_position;
	}
	else
		player->camera_position = new_position;
	printf("Camera position after turn left is: %d\n", player->camera_position);
	// redraw_map(player);
}
		
void turn_right(t_player_data *player)
{
	int new_position;

	new_position = player->camera_position - player->turn_speed;
	if (new_position < 1)
	{
		new_position = 360 + player->camera_position - player->turn_speed;
		player->camera_position = new_position;
	}
	else
		player->camera_position = new_position;
	printf("Camera position after turn right is: %d\n", player->camera_position);
	// redraw_map(player);
}
