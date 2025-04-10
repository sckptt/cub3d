/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:50:20 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/10 17:41:50 by vkinsfat         ###   ########.fr       */
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

int	is_wrong_id_order(char *map_line, char *identifier)
{
	char	**splitted_line;

	splitted_line = ft_split(map_line, ' ');
	if (!ft_strncmp(splitted_line[1], identifier, 1))
	{
		free_char_array(splitted_line);
		return (TRUE);
	}
	free_char_array(splitted_line);
	return (FALSE);
}
