/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:41:06 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/21 19:22:20 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(int angle_deg)
{
	return (angle_deg * M_PI / 180.0);
}

int	rad_to_deg(int angle_rad)
{
	return (angle_rad * 180.0 / M_PI);
}

int	is_passable(char **map, double y, double x)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)floor(x / 64);
	pos_y = (int)floor(y / 64);
	if (map[pos_y][pos_x] == '1')
	{
		printf("KO: Tile [%d][%d] is %c\n", pos_y, pos_x, map[pos_y][pos_x]);
		return (FALSE);
	}
	printf("OK: Tile [%d][%d] is %c\n", pos_y, pos_x, map[pos_y][pos_x]);
	return (TRUE);
}
