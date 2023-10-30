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

typedef struct s_cub3d
{
	void	*win;
	void	*mlx;
	float		px;
	float 	py;
}	t_cub3d;

#endif