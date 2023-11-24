#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SIZE_X || y < 0 || y >= SIZE_Y)
		return ;
	dst = data->img->addr + (y * data->img->line_length + x * (data->img->bpp / 8));
	*(unsigned int*)dst = color;
}
