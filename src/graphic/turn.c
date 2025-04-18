/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:42:56 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/24 19:09:49 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_player_data *player)
{
	player->camera_position = (player->camera_position - player->turn_speed + 360) % 360;
}

void	turn_right(t_player_data *player)
{
	player->camera_position = (player->camera_position + player->turn_speed) % 360;
}
