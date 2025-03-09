/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:51:34 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/09 19:03:23 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include "../Libft/include/libft.h"

# define BUFFER_SIZE 42
# define FALSE 0
# define TRUE 1

# define WRONG_ARGS_MSG "Error\nNumber of arguments is not 2!\n"
# define EXTRA_SYMBOLS_MSG "Error\nExtra symbols in the map!\n"
# define NO_WALL_MSG "Error\nMap is not surrounded by walls!\n"
# define WRONG_COLOR "Error\nRGB colors should be ints in range [0, 255]!\n"
# define MISSING_COLOR "Error\nFloor or ceiling color is missing!\n"
# define NO_CUB_MSG "Error\nFile is not .cub!\n"
# define WRONG_TEXTURE_PATH "Error\nPath to texture is wrong!\n"
# define TEXTURE_DUPLICATE "Error\nDuplicates in texture path!\n"
# define MISSING_TEXTURE "Error\nOne of textures is missing!\n"
# define MISSING_MAP "Error\nMap is missing!\n"
# define MULTIPLE_PLAYERS "Error\nNumber of players is more than 1!\n"
# define NO_PLAYERS "Error\nNumber of players is 0!\n"
# define EMPTY "Error\nEmpty file!\n"
# define WRONG_ORDER "Error\nWrong order of identifiers!\n"
# define TEXTURE_ERROR "Error\nProgram failed to load the texture!\n"
# define MLX_ERROR "Error\nProgram failed to initialize MLX!\n"
# define FILE_ERROR "Error\nProgram failed to open the file!\n"
# define ALLOC_ERROR "Error\nProgram failed to allocate memory!\n"

typedef struct s_appdata
{
	char **map;
	char *n_texture;
	char *s_texture;
	char *w_texture;
	char *e_texture;
	char **whole_map;
	int *floor_colors;
	int *ceiling_colors;
}	t_appdata;

//GNL
char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *str);

//parsing
int parse_map(t_appdata *appdata, char *path);

#endif