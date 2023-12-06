#include "cub3d.h"

int    error_exit(t_cub3d *data);

int	error_exit(t_cub3d *data)
{
	free(data->texture->north);
	free(data->texture->south);
	free(data->texture->east);
	free(data->texture->west);
	free(data->texture->door);
	free(data->texture);
	free(data->player);
	free(data->ray);
	if (data->texture->map)
		free_2d(data->texture->map);
	free(data);
	exit(1);
}