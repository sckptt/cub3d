/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:38:08 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/04/10 17:48:35 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_started(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (FALSE);
	}
	return (TRUE);
}

int	check_extra_id(t_appdata *appdata)
{
	int		i;
	char	**split_line;

	i = -1;
	while (++i < appdata->map->map_lines_total)
	{
		if (is_map_started(appdata->map->whole_map[i]) == TRUE)
			break ;
		split_line = ft_split(appdata->map->whole_map[i], ' ');
		if (!ft_strnstr("NOSOWEEAFC", split_line[0], ft_strlen("NOSOWEEAFC")))
		{
			free_char_array(split_line);
			return (FAILURE);
		}
		free_char_array(split_line);
	}
	return (SUCCESS);
}
