/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:51:34 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/14 15:53:31 by vkinsfat         ###   ########.fr       */
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
// commented out temporarly to avoid error message:
// # include "../MLX42/include/MLX42/MLX42.h"
// added by Y:
# include <math.h>

# define BUFFER_SIZE 42
# define FALSE 0
# define TRUE 1
# define FAILURE 1
# define SUCCESS 0
// added by Y:
# define PI 3.141592653589793
# define SCREEN_HEIGHT 1600
# define SCREEN_WIDTH 2560

//Common error messages
# define WRONG_ARGS_MSG "Error\nNumber of arguments is not 2!\n"
# define TEXTURE_LOADING_ERROR "Error\nProgram failed to load the texture!\n"
# define MLX_ERROR "Error\nProgram failed to initialize MLX!\n"
# define FILE_ERROR "Error\nProgram failed to open the file!\n"
# define ALLOC_ERROR "Error\nProgram failed to allocate memory!\n"
# define NO_CUB_MSG "Error\nFile is not .cub!\n"

//Color error messages
# define INVALID_RGB_VALUES "Error\nRGB colors should be ints in range [0, 255]!\n"
# define INVALID_RGB_AMOUNT "Error\nRGB colors should be represented with 3 ints\n"
# define COLOR_DUPLICATE "Error\nDuplicates in colors!\n"
# define MISSING_COLOR "Error\nFloor or ceiling color is missing!\n"

//Texture error messages
# define WRONG_TEXTURE_PATH "Error\nPath to texture is wrong!\n"
# define TEXTURE_DUPLICATE "Error\nDuplicates in texture path!\n"
# define MISSING_TEXTURE "Error\nOne of textures is missing!\n"
# define NON_PNG_TEXTURE "Error\nTexture is not .png file!\n"

//Map error messages
# define EXTRA_SYMBOLS_MSG "Error\nExtra symbols in the map!\n"
# define MISSING_MAP "Error\nMap is missing!\n"
# define MULTIPLE_PLAYERS "Error\nNumber of players is more than 1!\n"
# define MISSING_PLAYER "Error\nNo players found on the map!\n"
# define NO_WALL_MSG "Error\nMap is not surrounded by walls!\n"
# define EMPTY "Error\nEmpty file!\n"
# define WRONG_ORDER "Error\nWrong order of identifiers!\n"

typedef struct s_map_data
{
	char	**map;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	**whole_map;
	int		*floor_colors;
	int		*ceiling_colors;
	int		map_lines_total;
// added by Y:
	int		unit_size;

}	t_map_data;

typedef struct s_textures
{
	mlx_image_t	*north;
	mlx_image_t	*south;
	mlx_image_t	*west;
	mlx_image_t	*east;
	long		floor_color;
	long		ceiling_color;
}	t_textures;

typedef struct s_player_data
{
	int	pos_x;
	int	pos_y;
	int	camera_position;
	int	tile_pos_x;
	int	tile_pos_y;
	int	move_speed;
	int	turn_speed;
// added by Y:
	int	field_of_view_deg;
	int	field_of_view_rad;
	int	eyes_height;
	float	camera_position_rad;

}	t_player_data;

// added by Y:
typedef struct s_raycasting
{
	float	angle_btw_rays_rad;
	float	dist_to_plane;
	float	curr_ray_angle;
	float	closest_wall_dist;
	float	closest_wall_corrected;

	int	projected_slice_height;
	int	slice_starting_point;
	int	slice_end_point;
}	t_raycasting;


typedef struct s_appdata
{
	t_map_data		*map;
	mlx_t			*mlx;
	t_textures		*textures;
	t_player_data	*player;
// added by Y:
	t_raycasting	*raycast;

}	t_appdata;

//GNL
char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *str);

//parsing
char	*get_path(char *string);
int		count_non_empty_lines(t_appdata *appdata, char *path);
int		is_empty_line(char *line);
int		parse_map(t_appdata *appdata, char *path);
int		find_position(char **map, char id);
int		fill_the_structs(t_appdata *appdata);
int		*get_rgb_colors(char *string);

//error handling
char	**copy_array(char **array, int array_len);
char	**get_number_array(char *string);
int		*create_row_len_array(char **array);
int		check_map(t_appdata *appdata);
int		check_order(t_appdata *appdata);
int		count_identifiers(t_appdata *appdata, char *identifier);
int		count_length_of_array(char **array);
int		is_png_file(char *str);
int		is_valid_filename(const char *arg);
void	check_for_errors(t_appdata *appdata);
void	check_numeric(t_appdata *appdata, char *string);

//free memory
void	free_appdata(t_appdata *appdata);
void	free_char_array(char **array);
void	free_after_exit(void *param);

//init
void	init_appdata(t_appdata *appdata);

//graphic
void	start_mlx(t_appdata *appdata);
long	rgb_to_long(int *rgb_array);

// added by Y:
//maths
float	degrees_to_radians(float value_in_degrees);

#endif