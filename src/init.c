#include "cub3d.h"

void	init_textures(t_cub3d *data)
{
	printf("check\n");
	data->texture->north->path = NULL;
	data->texture->south->path = NULL;
	data->texture->east->path = NULL;
	data->texture->west->path = NULL;
	data->texture->door->path = NULL;

}

void	init_map_vars(t_cub3d *data)
{
	data->map->layout = NULL;
	data->map->height = 0;
	data->map->width = 0;
	data->map->pos_x = 0;
	data->map->pos_y = 0;
}

void init_data(t_cub3d *data, char *filename)
{

	init_textures(data);
	init_map_vars(data);
	init_map_size(data, filename);
	init_map_layout(data, filename);
}

int init_window(t_cub3d *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "cub3d");
	return (0);
}