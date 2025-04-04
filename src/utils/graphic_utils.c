/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:21:28 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/28 16:52:38 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	rgb_to_long(int *rgb_array)
{
	if (!rgb_array)
		return (0);
	return (rgb_array[0] << 24 | rgb_array[1] << 16 | rgb_array[2] << 8 | 0xFF);
}
