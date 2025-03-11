/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:44:37 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/11 13:59:21 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO - free memory
static void	flood_fill(char **map, int *row_len, int x, int y)
{
	if (x < 0 || y < 0 || y >= count_length_of_array(map)
		|| x > row_len[y])
	{
		ft_putstr_fd(NO_WALL_MSG, 2);
		free_char_array(map);
		free(row_len);
		row_len = NULL;
		exit(FAILURE);
	}
	if (x >= row_len[y] || map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, row_len, x + 1, y);
	flood_fill(map, row_len, x - 1, y);
	flood_fill(map, row_len, x, y + 1);
	flood_fill(map, row_len, x, y - 1);
}

static int	check_the_wall(t_map_data *map)
{
	char	**copy;
	int		*row_len;
	int		pos_x;
	int		pos_y;

	copy = copy_array(map->whole_map, map->map_lines_total);
	if (!copy)
		return (FAILURE);
	row_len = create_row_len_array(copy);
	if (!row_len)
		return (FAILURE);
	pos_x = find_position(copy, 'x');
	pos_y = find_position(copy, 'y');
	flood_fill(copy, row_len, pos_x, pos_y);
	if (copy)
		free_char_array(copy);
	if (row_len)
		free(row_len);
	return (SUCCESS);
}

static int	check_extra_symbols(t_map_data *map)
{
	int	i;
	int	j;

	i = 6;
	while (i < map->map_lines_total)
	{
		j = 0;
		while (map->whole_map[i][j])
		{
			if (ft_strchr("NSEW10 ", map->whole_map[i][j]))
				return (ft_putstr_fd(EXTRA_SYMBOLS_MSG, 2), FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_player(t_map_data *map)
{
	int	i;
	int	j;
	int	player_counter;

	i = 6;
	player_counter = 0;
	while (i < map->map_lines_total)
	{
		j = 0;
		while (map->whole_map[i][j])
		{
			if (ft_strchr("NSEW", map->whole_map[i][j]))
				player_counter++;
			j++;
		}
		i++;
	}
	if (player_counter == 0)
		return (ft_putstr_fd(MISSING_PLAYER, 2), FAILURE);
	else if (player_counter > 1)
		return (ft_putstr_fd(MULTIPLE_PLAYERS, 2), FAILURE);
	return (SUCCESS);
}

int	check_map(t_appdata *appdata)
{
	if (appdata->map->map_lines_total <= 6)
	{
		ft_putstr_fd(MISSING_MAP, 2);
		return (FAILURE);
	}
	if (check_player(appdata->map) == FAILURE)
		return (FAILURE);
	if (check_extra_symbols(appdata->map) == FAILURE)
		return (FAILURE);
	if (check_the_wall(appdata->map) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
