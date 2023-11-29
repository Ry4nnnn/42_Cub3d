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
	int			floor[3];
	int			ceiling[3];
	int			width;
	int			height;
}	t_texture;

typedef	struct s_player
{
	int		spawn_dir;
	float	pos_x;
	float	pos_y;
}	t_player;


typedef struct s_cub3d
{
	void		*win;
	void		*mlx;
	t_img_data	*img;
	char		**map;
	t_texture	*texture;
	t_player	*player;
	int			map_y;
	int			map_x;
}	t_cub3d;


/* PARSING */
int		parsing(t_cub3d *data, char *filename);
char	**open_file(char *filename);
int		check_valid_filename(char *filename);

/* MLX UTLIS*/
void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color);

/* UTLIS*/
void    free_2d(char **array);

/* INIT */
void    init_data(t_cub3d *data);

/* MAP_CHECK */
int	handle_file(t_cub3d *data, char **array);
// int		map_check(t_cub3d *data, char **file);

void    ft_error(t_cub3d *data, char *msg);

#endif