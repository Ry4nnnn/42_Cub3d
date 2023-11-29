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

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_texture
{
	t_img_data	*north;
	t_img_data	*south;
	t_img_data	*west;
	t_img_data	*east;
	t_img_data	*door;
	char		*floor;
	char		*ceiling;
	int			width;
	int			height;
}	t_texture;

typedef	struct s_player
{
	int		spawn_dir;
	float	pos_x;
	float	pos_y;
}	t_player;

typedef struct s_map
{
	int height;
	int width;
	char	**layout;
	int pos_x;
	int pos_y;
}	t_map;


typedef struct s_cub3d
{
	void		*win;
	void		*mlx;
	t_img_data	*img;
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
}	t_cub3d;


/* MLX UTLIS*/
void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color);

/* UTLIS*/
void    free_2d(char **array);

/* INIT */
void    init_data(t_cub3d *data, char *filename);
void	init_map_size(t_cub3d *data, char *filename);
void	init_map_layout(t_cub3d *data, char *filename);
int	handle_file(t_cub3d *data, char **array);
void	init_map_vars(t_cub3d *data);
void	init_textures(t_cub3d *data);
void init_data(t_cub3d *data, char *filename);
void    ft_error(t_cub3d *data, char *msg);
void	handle_wall(t_cub3d *data, char *row, int width);
void	handle_map(t_cub3d *data);
int init_window(t_cub3d *data);

#endif