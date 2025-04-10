/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:51:34 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/04 19:04:31 by vitakinsfat      ###   ########.fr       */
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
//CHANGED BY Y
# define MOVE_SPEED 8
# define TURN_SPEED 8

# define TILE_SIZE 64
# define EYES_HEIGHT 32

//Common error messages
# define WRONG_ARGS_MSG "Error\nNumber of arguments is not 2!\n"
# define TEXTURE_LOADING_ERROR "Error\nProgram failed to load the texture!\n"
# define IMAGE_CREATION_ERROR "Error\nProgram failed to create the image!\n"
# define MLX_ERROR "Error\nProgram failed to initialize MLX!\n"
# define FILE_ERROR "Error\nProgram failed to open the file!\n"
# define ALLOC_ERROR "Error\nProgram failed to allocate memory!\n"
# define NO_CUB_MSG "Error\nFile is not .cub!\n"

//Color error messages
# define INVALID_RGB_VALUES "Error\nRGB should be ints in range [0, 255]!\n"
# define INVALID_RGB_AMOUNT "Error\nRGB should be represented with 3 ints\n"
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
	mlx_image_t		*north;
	mlx_image_t		*south;
	mlx_image_t		*west;
	mlx_image_t		*east;
	mlx_image_t		*view;
	unsigned int	floor_rgba;
	unsigned int	ceil_rgba;
}	t_textures;

typedef struct s_player_data
{
	float	camera_angle_r;
	float	tile_pos_x;
	float	tile_pos_y;
	int		pos_x;
	int		pos_y;
	int		camera_angle_d;

//ADDED TO HANDLE LOOKING LEFT OR RIGHT
	int		original_angle;
	int		is_looking_side;

}	t_player_data;

typedef struct s_raycasting
{
	float	angle_btw_rays_rad;
	float	dist_to_plane;
	float	curr_ray;
	float	wall_dist;
	float	correct_dist;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		map_x;
	int		map_y;
	int		slice_height;
	int		wall_start;
	int		wall_end;
	int		wall_side;
//ADDED FOR TEXTURE HANDLING:
	float	wall_x;          // Where exactly the wall was hit (for texturing)
	int     tex_x;           // X coordinate on the texture
	int     tex_y;           // Y coordinate on the texture
	int     tex_step;        // How much to increase the texture coordinate per screen pixel
	int     tex_pos;         // Starting texture position
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
char			*get_next_line(int fd);
char			*gnl_strjoin(char const *s1, char const *s2);
size_t			gnl_strlen(const char *str);

//parsing
char			*get_path(char *string);
int				count_non_empty_lines(t_appdata *appdata, char *path);
int				is_empty_line(char *line);
int				parse_map(t_appdata *appdata, char *path);
int				find_position(char **map, char id);
int				fill_the_structs(t_appdata *appdata);
int				*get_rgb_colors(char *string);

//error handling
char			**copy_array(char **array, int array_len);
char			**get_number_array(t_appdata *appdata, char *string);
int				*create_row_len_array(char **array);
int				check_map(t_appdata *appdata);
int				check_order(t_appdata *appdata);
int				count_identifiers(t_appdata *appdata, char *identifier);
int				count_array_len(char **array);
int				is_png_file(char *str);
int				is_valid_filename(const char *arg);
void			check_for_errors(t_appdata *appdata);
void			check_numeric(t_appdata *appdata, char *string);
char			*remove_extra_spaces(char *string);

//free memory
void			free_appdata(t_appdata *appdata);
void			free_char_array(char **array);
void			free_after_exit(void *param);

//init
void			init_appdata(t_appdata *appdata);

//graphic
void			start_mlx(t_appdata *appdata);
unsigned int	rgb_to_long(int *rgb_array);
void			hook_the_keys(mlx_key_data_t keydata, void *param);
void			redraw_map(t_appdata *appdata);
//ADDED TO HANDLE LOOKING LEFT OR RIGHT
void			reset_look(t_appdata *appdata);
void			look_right(t_appdata *appdata);
void			look_left(t_appdata *appdata);

//maths
int				is_passable(char **map, float y, float x);
double			deg_to_rad(int angle_deg);
float			set_ray_angle(int ray_index, t_player_data *player);
void			iterate_casted_rays(t_appdata *appdata);
int				get_step_x(t_appdata *appdata);
int				get_step_y(t_appdata *appdata);
int				hit_check(t_raycasting *raycast,
					t_map_data *map, int step_y, int step_x);

//textures calculations
void			calculate_wall_hit_position(t_appdata *appdata);
mlx_image_t		*get_texture_for_side(t_appdata *appdata);
void			calculate_texture_x(t_appdata *appdata, mlx_image_t *texture);
void			draw_textured_wall_slice(t_appdata *appdata, int ray_index);
void			draw_ceiling_and_floor(t_appdata *appdata, int ray_index);

#endif
