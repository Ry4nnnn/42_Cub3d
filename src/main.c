#include "cub3d.h"

int	error_check(t_cub3d *data, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./program [map]\n", 2);
		return (1);
	}
	data = ft_calloc(1, sizeof(t_cub3d));
	init_data(data);
	if (parsing(data, argv[1]) == 1)
		return (1);
	return (0);

}

int main(int argc, char	**argv)
{
	t_cub3d	*data;

	data = ft_calloc(1, sizeof(t_cub3d));
	if (error_check(data, argc, argv) == 1)
	{
		free(data);
		exit(1);
	}
	// mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	// mlx_hook(data->win, 2, 1L << 0, NULL, &data);
	// mlx_loop(data->mlx);
	return (0);
}