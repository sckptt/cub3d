/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:21:28 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/14 15:44:56 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	rgb_to_long(int *rgb_array)
{
	long	r;
	long	g;
	long	b;

	if (!rgb_array)
		return (0);
	r = (rgb_array[0] & 0xff) << 16;
	g = (rgb_array[1] & 0xff) << 8;
	b = (rgb_array[2] & 0xff);
	return (r + g + b);
}
