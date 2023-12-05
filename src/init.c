#include "cub3d.h"


void    init_data(t_cub3d *data)
{
	data->mlx = mlx_init();
	// data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cub3d");
	// data->img = ft_calloc(1, sizeof(t_img_data));
	// data->img->img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	// data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, &data->img->line_length, &data->img->endian);
	data->texture = ft_calloc(1, sizeof(t_texture));
	data->texture->north = ft_calloc(1, sizeof(t_img_data));
	data->texture->south = ft_calloc(1, sizeof(t_img_data));
	data->texture->west = ft_calloc(1, sizeof(t_img_data));
	data->texture->east = ft_calloc(1, sizeof(t_img_data));
	data->texture->door = ft_calloc(1, sizeof(t_img_data));
    data->player = ft_calloc(1, sizeof(t_player));
    data->player->px = 26.25;
	data->player->py = 11.25;
    data->player->dirx = -1;
    data->player->diry =  0;
    data->player->planex = 0;
    data->player->planey = 0.45;
    data->player->t = 0;
    data->player->old_t = 0;
    data->ray = ft_calloc(1, sizeof(t_ray));
	data->ray->north_south = -1;
	data->ray->east_west = -1;
}
