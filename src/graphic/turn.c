/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:42:56 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/03 12:14:44 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_player_data *player)
{
	player->camera_position_deg = (player->camera_position_deg - TURN_SPEED + 360) % 360;
}

void	turn_right(t_player_data *player)
{
	player->camera_position_deg = (player->camera_position_deg + TURN_SPEED) % 360;
}
