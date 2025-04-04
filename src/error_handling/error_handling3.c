/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:50:20 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/04 18:09:37 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_line_index(char **whole_map, char *identifier)
{
	int	i;

	i = -1;
	while (whole_map[++i])
	{
		if (ft_strnstr(whole_map[i], identifier, ft_strlen(whole_map[i])))
			return (i);
	}
	return (-1);
}

int	check_order(t_appdata *appdata)
{
	if (find_line_index(appdata->map->whole_map, "NO ") > 5)
		return (ft_putstr_fd(WRONG_ORDER, 2), FAILURE);
	if (find_line_index(appdata->map->whole_map, "SO ") > 5)
		return (ft_putstr_fd(WRONG_ORDER, 2), FAILURE);
	if (find_line_index(appdata->map->whole_map, "WE ") > 5)
		return (ft_putstr_fd(WRONG_ORDER, 2), FAILURE);
	if (find_line_index(appdata->map->whole_map, "EA ") > 5)
		return (ft_putstr_fd(WRONG_ORDER, 2), FAILURE);
	if (find_line_index(appdata->map->whole_map, "F ") > 5)
		return (ft_putstr_fd(WRONG_ORDER, 2), FAILURE);
	if (find_line_index(appdata->map->whole_map, "C ") > 5)
		return (ft_putstr_fd(WRONG_ORDER, 2), FAILURE);
	return (SUCCESS);
}

int	is_png_file(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'g' || str[i - 1] != 'n'
		|| str[i - 2] != 'p'
		|| str[i - 3] != '.')
		return (FALSE);
	return (TRUE);
}
