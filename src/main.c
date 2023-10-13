#include "cub3d.h"


void	drawPlayer(t_cub3d data)
{
	data.px = 300;
	data.py = 300;
	mlx_pixel_put(data.mlx, data.win, data.px, data.py, 0xFFFFFF);
}

// void	map_reading(t_cub3d *data, char *filename)
// {
	
// }

int main(int argc, char	**argv)
{
	t_cub3d	data;

	if (argc != 2)
	{
		printf("Usage: ./program [map]");
		exit(1);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1000, 500, "cub3d");
	// map_reading(&data, argv[1]);
	drawPlayer(data);
	mlx_hook(data.win, 2, 1L << 0, NULL, &data);
	mlx_loop(data.mlx);
	return (0);
}