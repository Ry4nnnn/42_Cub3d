/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:42:08 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 19:03:55 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

# define SIZE_X 900
# define SIZE_Y 900
# define PI 3.1415926535
# define RED 0x00FF0000
# define BLUE 0x004848F5
# define GREEN 0x0043BF77
# define ORANGE 0x00FF9B00

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# ifdef __linux__

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# elif defined __APPLE__

# define KEY_ESC 253
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# endif

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_image
{
	int		start_x;
	int		start_y;
	int		dest_x;
	int		dest_y;
	int		colour;
}	t_image;

typedef struct s_img_data
{
	void	*img_ptr;
	void	*img;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img_data;

typedef struct s_ray
{
	double	raydirx;
	double	raydiry;
	int		mx;
	int		my;
	double	xo;
	double	yo;
	double	dx;
	double	dy;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		hit;
	int		north_south;
	int		east_west;
	int		side;
}	t_ray;

typedef struct s_player
{
	double	px;
	double	py;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	t;
	double	old_t;
	int		news;
}	t_player;

typedef struct s_texture
{
	t_img_data	*north;
	t_img_data	*south;
	t_img_data	*east;
	t_img_data	*west;
	t_img_data	*door;
	int			floor;
	int			ceiling;
	char		**map;
	int			width;
	int			height;
	int			flag;
}	t_texture;

typedef struct s_cub3d
{
	void		*win;
	void		*mlx;
	t_img_data	*img;
	t_texture	*texture;
	t_player	*player;
	t_ray		*ray;
	t_img_data	*current_texture;
}	t_cub3d;

/* ERROR_CHECK */
int		error_check(t_cub3d *data, int argc, char **argv);
int		check_valid_filename(char *filename);

/* PARSING */
int		parsing(t_cub3d *data, char *filename);
char	**open_file(char *filename);

/* INIT */
void	init_data(t_cub3d *data);
int		init_file_data(t_cub3d *data, char **array);
int		init_map_layout(t_cub3d *data, char **array, int i);

/* INIT_FLOOR_TEXTURE */
int		init_fc_color(t_cub3d *data, char *str);

/* INIT_TEXTURES */
int		init_textures(t_cub3d *data, char *str);

/* INIT_TEXTURES_UTILS */
int		init_north(t_cub3d *data, char *path);
int		init_south(t_cub3d *data, char *path);
int		init_west(t_cub3d *data, char *path);
int		init_east(t_cub3d *data, char *path);
int		init_door(t_cub3d *data, char *path);

/* INIT_PLAYER_DATA */
void	init_player_data(t_cub3d *data, int x, int y, int dir);

/* MAP_CHECK */
void	map_resize(t_cub3d *data);
int		check_map(t_cub3d *data);

/* CHECK_VALID_MAP */
int		check_valid_map(t_cub3d *data);

/* DRAWMAP */
void	drawmap(t_cub3d	*data);

/* DRAWTEXTURE */
void	draw_texture(t_cub3d *data, int x);

/* DRAWRAY */
void	drawray(t_cub3d *data);

/* DRAW_UTLIS */
void	half_window(t_cub3d *data, int colour1, int colour2);
void	change_colour(t_cub3d *data, t_image *img);
void	drawsquare(t_cub3d	*data, int x, int y, int colour);
int		is_wall(t_cub3d *data, int x, int y);

/* KEY_HOOK */
int		key_hook(int keycode, t_cub3d *data);
int		exit_hook(t_cub3d *data);

/* EXIT */
int		error_exit(t_cub3d *data);

/* UTLIS*/
void	free_2d(char **array);
int		rgb_to_hex(int r, int g, int b);

/* MLX UTLIS*/
void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color);

#endif