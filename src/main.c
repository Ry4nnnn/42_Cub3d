#include "cub3d.h"

int	error_check(t_cub3d *data, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./program [map]\n", 2);
		return (1);
	}
	init_data(data);
	if (parsing(data, argv[1]) == 1)
		return (1);
	return (0);

}

int	loop_hook(t_cub3d *data)
{
	half_window(data, 0x0020487E, 0x00D4E59E);
	drawRay(data);
	drawMap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
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
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cub3d");
	data->img = ft_calloc(1, sizeof(t_img_data));
	data->img->img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
                                &data->img->line_length, &data->img->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	data->news = ft_calloc(1, sizeof(t_news));
	data->news->north = ft_calloc(1, sizeof(t_img_data));
	data->news->north->img_ptr = mlx_xpm_file_to_image(data->mlx, "./images/as.xpm", &data->news->north->width, &data->news->north->height);
	data->news->north->addr = mlx_get_data_addr(data->news->north->img_ptr, &data->news->north->bpp,
								&data->news->north->line_length, &data->news->north->endian);
	if (data->news->north != NULL)
		printf("north width %d height %d\n", data->news->north->width, data->news->north->height);
	// mlx_put_image_to_window(data->mlx, data->win, data->news->north->img_ptr, 0, 0);
	// data->news->south = ft_calloc(1, sizeof(t_img_data));
	// data->news->south = mlx_xpm_file_to_image(data->mlx, "./images/minecraft_wood.xpm", &data->news->south->width, &data->news->south->height);
	// // data->news->south->addr = mlx_get_data_addr(data->news->south->img, &data->news->south->bpp,
	// // 							&data->news->south->line_length, &data->news->south->endian);
	// if (data->news->south != NULL)
	// 	printf("south width %d height %d\n", data->news->south->width, data->news->south->height);
	
	// data->news->east = ft_calloc(1, sizeof(t_img_data));
	// data->news->east = mlx_xpm_file_to_image(data->mlx, "./images/as.xpm", &data->news->east->width, &data->news->east->height);
	// // data->news->east->addr = mlx_get_data_addr(data->news->east->img, &data->news->east->bpp,
	// // 							&data->news->east->line_length, &data->news->east->endian);
	// if (data->news->east != NULL)
	// 	printf("east width %d height %d\n", data->news->east->width, data->news->east->height);
	
	// data->news->west = ft_calloc(1, sizeof(t_img_data));
	// data->news->west = mlx_xpm_file_to_image(data->mlx, "./images/kl_tower.xpm", &data->news->west->width, &data->news->west->height);
	// // data->news->west->addr = mlx_get_data_addr(data->news->west->img, &data->news->west->bpp,
	// // 							&data->news->west->line_length, &data->news->west->endian);
	// if (data->news->west != NULL)
	// 	printf("west width %d height %d\n", data->news->west->width, data->news->west->height);
	
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 1L << 17, exit_hook, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
	mlx_loop(data->mlx);
	return (0);
}