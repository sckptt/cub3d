/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:33:08 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/11 13:42:25 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	count_non_empty_lines(t_appdata *appdata, char *path)
{
	int		counter;
	int		fd;
	char	*line;

	counter = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(FILE_ERROR, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_empty_line(line))
			counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

int	find_position(char **map, char id)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				if (id == 'x')
					return (j);
				else
					return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}
