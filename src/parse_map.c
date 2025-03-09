/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:08:03 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/09 19:22:26 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_empty_line(char *line)
{
	int i;

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

int count_non_empty_lines(char *path)
{
	int counter;
	int fd;
	char *line;
	
	counter = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(FILE_ERROR, 2);
		// free_appdata(appdata);
		exit(1);
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

void allocate_memory_for_whole_map(t_appdata *appdata, int line_num)
{
	appdata->whole_map = malloc(sizeof(char *) * (line_num + 1));
	if (!appdata->whole_map)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		// free_appdata(appdata);
		exit(1);
	}
}

void fill_whole_map(t_appdata *appdata, int fd, int num_of_lines)
{
	int i;
	char *line;
	
	i = 0;
	line = get_next_line(fd);
	while (i < num_of_lines)
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
	int non_empty_lines;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(FILE_ERROR, 2);
		// free_appdata(appdata);
		exit(1);
	}
	non_empty_lines = count_non_empty_lines(path);
	allocate_memory_for_whole_map(appdata, non_empty_lines);
	fill_whole_map(appdata, fd, non_empty_lines);
	close(fd);
	return (0);
}
