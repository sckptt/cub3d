/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:33:08 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/09 19:34:24 by vitakinsfat      ###   ########.fr       */
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
