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

// typedef struct s_map_info
// {
// 	char	key;
// 	char	*value;
// }	t_map_info;

typedef struct s_texture
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
	void	*door;
	int		floor[3];
	int		ceiling[3];
	int		width;
	int		height;
}	t_texture;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_cub3d
{
	void		*win;
	void		*mlx;
	t_img_data	*img;
	char		**map;
	// t_list		*map_info;
	t_texture		texture;
	
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
int		map_check(t_cub3d *data, char **file);

void    ft_error(t_cub3d *data, char *msg);

#endif