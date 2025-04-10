/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:51:34 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/10 19:06:45 by vkinsfat         ###   ########.fr       */
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
# define SCREEN_HEIGHT 1080
# define SCREEN_WIDTH 1920
# define FOV_D 60
# define FOV_R 1.047
# define MOVE_SPEED 8
# define TURN_SPEED 8
# define TILE_SIZE 64

//Common error messages
# define ALLOC_ERROR "Error\nProgram failed to allocate memory!\n"
# define FILE_ERROR "Error\nProgram failed to open the file!\n"
# define IMAGE_CREATION_ERROR "Error\nProgram failed to create the image!\n"
# define MLX_ERROR "Error\nProgram failed to initialize MLX!\n"
# define NO_CUB_MSG "Error\nFile is not .cub!\n"
# define TEXTURE_LOADING_ERROR "Error\nProgram failed to load the texture!\n"
# define WRONG_ARGS_MSG "Error\nNumber of arguments is not 2!\n"

//Color error messages
# define COLOR_DUPLICATE "Error\nDuplicates in colors!\n"
# define INVALID_RGB_VALUES "Error\nRGB should be ints in range [0, 255]!\n"
# define INVALID_RGB_AMOUNT "Error\nRGB should be represented with 3 ints\n"
# define MISSING_COLOR "Error\nFloor or ceiling color is missing!\n"

//Texture error messages
# define MISSING_TEXTURE "Error\nOne of textures is missing!\n"
# define NON_PNG_TEXTURE "Error\nTexture is not .png file!\n"
# define NON_EXISTING_TEXTURE "Error\nTexture does not exist!\n"
# define TEXTURE_DUPLICATE "Error\nDuplicates in texture path!\n"
# define WRONG_TEXTURE_PATH "Error\nPath to texture is wrong!\n"

//Map error messages
# define EMPTY "Error\nEmpty file!\n"
# define EXTRA_SYMBOLS_MSG "Error\nExtra symbols in the map!\n"
# define MISSING_MAP "Error\nMap is missing!\n"
# define MISSING_PLAYER "Error\nNo players found on the map!\n"
# define MULTIPLE_PLAYERS "Error\nNumber of players is more than 1!\n"
# define NO_WALL_MSG "Error\nMap is not surrounded by walls!\n"
# define SPACE_FOUND "Error\nSpace instead of 0!\n"
# define WRONG_IDENTIFIER "Error\nWrong identifier in the map!\n"
# define WRONG_ID_ORDER "Error\nPath before identifier!\n"
# define WRONG_ORDER "Error\nWrong order of identifiers!\n"

typedef struct s_map_data
{
	char	**copy_map;
	char	**map;
	char	**whole_map;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;
	int		*ceiling_colors;
	int		*floor_colors;
	int		*row_len;
	int		map_lines_total;
}	t_map_data;

typedef struct s_textures
{
	mlx_image_t		*north;
	mlx_image_t		*south;
	mlx_image_t		*east;
	mlx_image_t		*west;
	mlx_image_t		*view;
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*east_texture;
	mlx_texture_t	*west_texture;
	unsigned int	floor_rgba;
	unsigned int	ceil_rgba;
}	t_textures;

typedef struct s_player_data
{
	float	camera_angle_r;
	float	tile_pos_x;
	float	tile_pos_y;
	int		camera_angle_d;
	int		is_looking_side;
	int		original_angle;
	int		pos_x;
	int		pos_y;
}	t_player_data;

typedef struct s_raycasting
{
	float	angle_btw_rays_rad;
	float	correct_dist;
	float	curr_ray;
	float	delta_dist_x;
	float	delta_dist_y;
	float	dist_to_plane;
	float	side_dist_x;
	float	side_dist_y;
	float	wall_dist;
	float	wall_x;
	int		map_x;
	int		map_y;
	int		slice_height;
	int		tex_pos;
	int		tex_step;
	int		tex_x;
	int		tex_y;
	int		wall_start;
	int		wall_end;
	int		wall_side;
}	t_raycasting;

typedef struct s_appdata
{
	t_map_data		*map;
	mlx_t			*mlx;
	t_player_data	*player;
	t_raycasting	*raycast;
	t_textures		*textures;
}	t_appdata;

//GNL
char			*get_next_line(int fd);
char			*gnl_strjoin(char const *s1, char const *s2);
size_t			gnl_strlen(const char *str);

//parsing
char			*get_path(char *string);
int				*get_rgb_colors(char *string);
int				count_non_empty_lines(t_appdata *appdata, char *path);
int				fill_the_structs(t_appdata *appdata);
int				find_position(char **map, char id);
int				is_empty_line(char *line);
int				parse_map(t_appdata *appdata, char *path);

//error handling
char			**copy_array(char **array, int array_len);
char			**get_number_array(t_appdata *appdata, char *string);
char			*remove_extra_spaces(char *string);
int				*create_row_len_array(char **array);
int				check_extra_id(t_appdata *appdata);
int				check_map(t_appdata *appdata);
int				check_order(t_appdata *appdata);
int				count_array_len(char **array);
int				count_identifiers(t_appdata *appdata, char *identifier);
int				is_png_file(char *str);
int				is_valid_filename(const char *arg);
int				is_wrong_id_order(char *map_line, char *identifier);
void			check_for_errors(t_appdata *appdata);
void			check_numeric(t_appdata *appdata, char *string);

//free memory
void			free_after_exit(void *param);
void			free_appdata(t_appdata *appdata);
void			free_char_array(char **array);

//init
void			init_appdata(t_appdata *appdata);

//graphic
mlx_image_t		*get_texture_for_side(t_appdata *appdata);
unsigned int	rgb_to_long(int *rgb_array);
void			hook_the_keys(mlx_key_data_t keydata, void *param);
void			look_left(t_appdata *appdata, t_player_data *player);
void			look_right(t_appdata *appdata, t_player_data *player);
void			reset_look(t_appdata *appdata, t_player_data *player);
void			redraw_map(t_appdata *appdata);
void			start_mlx(t_appdata *appdata);

//maths
double			deg_to_rad(int angle_deg);
float			set_ray_angle(int ray_index, t_player_data *player);
int				get_step_x(t_appdata *appdata);
int				get_step_y(t_appdata *appdata);
int				hit_check(t_raycasting *raycast,
					t_map_data *map, int step_y, int step_x);
int				is_passable(char **map, float y, float x);
void			iterate_casted_rays(t_appdata *appdata);

//textures calculations
mlx_image_t		*get_texture_for_side(t_appdata *appdata);
void			calculate_texture_x(t_appdata *appdata, mlx_image_t *texture);
void			calculate_wall_hit_position(t_appdata *appdata);
void			draw_ceiling_and_floor(t_appdata *appdata, int ray_index);
void			draw_textured_wall_slice(t_appdata *appdata, int ray_index);

#endif
