/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrouzaud <yrouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/03/25 10:31:20 by yrouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	degrees_to_radians(float value_in_degrees)
{
	float	value_in_radians;

	value_in_radians = value_in_degrees * (PI / 180);
	return (value_in_radians);
}

