#include "cub3d.h"

int	loop_hook(t_cub3d *data)
{
	half_window(data, 0x0020487E, 0x00D4E59E);
	drawRay(data);
	// drawMap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int main(int argc, char	**argv)
{
	t_cub3d	*data;

	data = ft_calloc(1, sizeof(t_cub3d));
	if (error_check(data, argc, argv) == 1)
		error_exit(data);
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cub3d");
	data->img = ft_calloc(1, sizeof(t_img_data));
	data->img->img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
                                &data->img->line_length, &data->img->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 1L << 17, exit_hook, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
