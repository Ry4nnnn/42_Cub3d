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

# define SIZE_X 1000
# define SIZE_Y 1000
# define PI 3.1415926535
# define RED 0x00FF0000
# define BLUE 0x004848F5

typedef struct s_image
{
	int	start_x;
	int	start_y;
	int	dest_x;
	int	dest_y;
	int	colour;
}	t_image;

typedef struct s_map_info
{
	char	key;
	char	*value;
}	t_map_info;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef	struct s_ray
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
	int		side;
}	t_ray;

typedef	struct	s_player
{
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	int		pa;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	t_ray	*ray;
	double	t;
	double	old_t;
}	t_player;

typedef struct s_cub3d
{
	void		*win;
	void		*mlx;
	t_img_data	*img;
	char		**map;
	int			map_width;
	int			map_height;
	t_list		*map_info;
	t_player	*player;
}	t_cub3d;


/* PARSING */
int		parsing(t_cub3d *data, char *filename);
char	**open_file(char *filename);
int		check_valid_filename(char *filename);

/* MLX UTLIS*/
void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color);

/* UTLIS*/
void    free_2d(char **array);
void    ft_swap(int *a, int *b);
int		degree_to_radian(float degree);
int 	ft_abs(int a);

/* INIT */
void    init_data(t_cub3d *data);

/* MAP_CHECK */
int		map_check(t_cub3d *data, char **file);

/* DRAW_UTLIS */
void    change_colour(t_cub3d *data, t_image *img);
void    half_window(t_cub3d *data, int colour1, int colour2);
void	drawLine(t_cub3d	*data, int x1, int y1, int x2, int y2, int colour);
void	drawSquare(t_cub3d	*data, int x, int y, int colour);

/* DRAW */
void	drawPlayer(t_cub3d  *data);
void    drawMap(t_cub3d	*data);
void    drawRay(t_cub3d *data);
void	drawWall(t_cub3d *data);
int		is_wall(t_cub3d *data, int x, int y);


/* KEY_HOOK */
int		key_hook(int keycode, t_cub3d *data);

#endif