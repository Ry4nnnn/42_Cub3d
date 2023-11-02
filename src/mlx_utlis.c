#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_length + x * (data->img->bpp / 8));
	*(unsigned int*)dst = color;
}
