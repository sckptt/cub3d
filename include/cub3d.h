/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:51:34 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/27 18:41:40 by vitakinsfat      ###   ########.fr       */
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
# include <math.h>
# include "../Libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define BUFFER_SIZE 42
# define FALSE 0
# define TRUE 1
# define FAILURE 1
# define SUCCESS 0
# define PI 3.141592653589793
# define SCREEN_HEIGHT 400
# define SCREEN_WIDTH 800
# define FOV_D 60
# define FOV_R 1.047
# define MOVE_SPEED 10
# define TURN_SPEED 30
# define TILE_SIZE 64
# define EYES_HEIGHT 32

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
# define SPACE_FOUND "Error\nSpace instead of 0!\n"

typedef struct s_map_data
{
	char	**map;
	char	**copy_map;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	**whole_map;
	int		*floor_colors;
	int		*ceiling_colors;
	int		*row_len;
	int		map_lines_total;

}	t_map_data;

typedef struct s_textures
{
	mlx_image_t	*north;
	mlx_image_t	*south;
	mlx_image_t	*west;
	mlx_image_t	*east;
	mlx_image_t *player;       //temporary
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
	float	camera_position_rad;

}	t_player_data;

typedef struct s_raycasting
{
	float	angle_btw_rays_rad;
	float	dist_to_plane;
	float	curr_ray_angle;
	float	closest_wall_dist;
	float	closest_wall_corrected;
	int	first_h_intersection_coord_x;
	int	first_h_intersection_coord_y;
	int	next_h_intersection_coord_x;
	int	next_h_intersection_coord_y;
	int	first_v_intersection_coord_x;
	int	first_v_intersection_coord_y;
	int	next_v_intersection_coord_x;
	int	next_v_intersection_coord_y;
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
	t_raycasting	*raycast;

}	t_appdata;

//GNL
char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *str);

//parsing
char	*get_path(char *string);
int		count_non_empty_lines(t_appdata *appdata, char *path);
int		count_width(char **map);
int		is_empty_line(char *line);
int		parse_map(t_appdata *appdata, char *path);
int		find_position(char **map, char id);
int		fill_the_structs(t_appdata *appdata);
int		*get_rgb_colors(char *string);

//error handling
char	**copy_array(char **array, int array_len);
char	**get_number_array(t_appdata *appdata, char *string);
int		*create_row_len_array(char **array);
int		check_map(t_appdata *appdata);
int		check_order(t_appdata *appdata);
int		count_identifiers(t_appdata *appdata, char *identifier);
int		count_length_of_array(char **array);
int		is_png_file(char *str);
int		is_valid_filename(const char *arg);
void	check_for_errors(t_appdata *appdata);
void	check_numeric(t_appdata *appdata, char *string);
char	*remove_extra_spaces(char *string);

//free memory
void	free_appdata(t_appdata *appdata);
void	free_char_array(char **array);
void	free_after_exit(void *param);

//init
void	init_appdata(t_appdata *appdata);

//graphic
void	start_mlx(t_appdata *appdata);
long	rgb_to_long(int *rgb_array);
void	draw_player_square(t_appdata *appdata);
void	hook_the_keys(mlx_key_data_t keydata, void *param);
int	is_passable(char **map, double y, double x);
double	deg_to_rad(int angle_deg);
void	turn_left(t_player_data *player);
void	turn_right(t_player_data *player);


// added by Y:
//maths
float	degrees_to_radians(float value_in_degrees);
void	iterate_casted_rays(t_appdata *appdata);
void	wall_height_for_drawing(t_appdata *appdata);
float	correct_fishbowl_effect(t_appdata *appdata);
float	closest_wall_distance(t_appdata *appdata);
float	first_vertical_wall_dist(t_appdata *appdata);
float	first_horizont_wall_dist(t_appdata *appdata);
float	calc_wall_distance(t_appdata *appdata, int intersection_x);
int	check_if_wall_at(t_appdata *appdata);
void	find_next_v_inters_coord(t_appdata *appdata, int iteration);
void	find_1st_v_inters_coord(t_appdata *appdata);
void	find_next_h_inters_coord(t_appdata *appdata, int iteration);
void	find_1st_h_inters_coord(t_appdata *appdata);
float	set_alpha_angle(t_appdata *appdata);
float	set_ray_angle(int casted_ray_index, t_appdata *appdata);

#endif
