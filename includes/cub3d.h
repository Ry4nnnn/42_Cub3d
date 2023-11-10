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

# define SIZE_X 500
# define SIZE_Y 500
# define PI 3.1415926535

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

typedef	struct	s_player
{
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	t;
	double	old_t;
}	t_player;

typedef struct s_cub3d
{
	void		*win;
	void		*mlx;
	t_img_data	*img;
	char		**map;
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

/* COLOUR */
void    change_colour(t_cub3d *data, t_image *img);
void    half_window(t_cub3d *data, int colour1, int colour2);
void	drawPlayer(t_cub3d  *data);
void    drawMap(t_cub3d	*data);

/* KEY_HOOK */
int		key_hook(int keycode, t_cub3d *data);

#endif