/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:08:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/09 21:52:57 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Ok, map has kinda weird format - path to texture, 
//then floor and ceiling colors, then map (and all it in one file!).
//On this step I just put everything (excluding empty lines) in 
//appdata->whole_map. Want to check it for errors.

void allocate_memory_for_whole_map(t_appdata *appdata)
{
	appdata->whole_map = malloc(sizeof(char *) * (appdata->map_lines_total + 1));
	if (!appdata->whole_map)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		// free_appdata(appdata);
		exit(1);
	}
}

void fill_whole_map(t_appdata *appdata, int fd)
{
	int i;
	char *line;
	
	i = 0;
	line = get_next_line(fd);
	while (i < appdata->map_lines_total)
	{
		if (!is_empty_line(line))
		{
			appdata->whole_map[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	appdata->whole_map[i] = NULL;
}

int parse_map(t_appdata *appdata, char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(FILE_ERROR, 2);
		// free_appdata(appdata);
		exit(1);
	}
	appdata->map_lines_total = count_non_empty_lines(path);
	if (appdata->map_lines_total == 0)
	{
		ft_putstr_fd(EMPTY, 2);
		// free_appdata(appdata);
		exit(1);
	}
	allocate_memory_for_whole_map(appdata);
	fill_whole_map(appdata, fd);
	return (0);
}
