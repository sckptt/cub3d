/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:26:48 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:07:23 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*fill_buffer(char *buffer, int fd)
{
	char	*new_buffer;
	ssize_t	bytes_read;

	new_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!new_buffer)
		return (NULL);
	bytes_read = 1;
	while (buffer == NULL || (!ft_strchr(buffer, '\n') && bytes_read > 0))
	{
		bytes_read = read(fd, new_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_buffer);
			new_buffer = NULL;
			return (NULL);
		}
		new_buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		buffer = gnl_strjoin(buffer, new_buffer);
	}
	free(new_buffer);
	return (buffer);
}

static char	*read_one_line(char *str)
{
	char	*one_line;
	int		i;

	i = 0;
	if (!str || str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	one_line = (char *)malloc(i + 2);
	if (!one_line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		one_line[i] = str[i];
		i++;
	}
	one_line[i] = '\0';
	return (one_line);
}

static char	*renew_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(gnl_strlen(buffer) - i + 1);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fill_buffer(buffer, fd);
	line = read_one_line(buffer);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	buffer = renew_buffer(buffer);
	return (line);
}
