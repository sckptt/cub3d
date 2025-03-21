/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:42:56 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/21 22:31:33 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_player_data *player)
{
	int	new_position;

	new_position = player->camera_position + player->turn_speed;
	if (new_position > 360)
	{
		new_position = player->turn_speed - 360 + player->camera_position;
		player->camera_position = new_position;
	}
	else
		player->camera_position = new_position;
}

void	turn_right(t_player_data *player)
{
	int	new_position;

	new_position = player->camera_position - player->turn_speed;
	if (new_position < 1)
	{
		new_position = 360 + player->camera_position - player->turn_speed;
		player->camera_position = new_position;
	}
	else
		player->camera_position = new_position;
}
