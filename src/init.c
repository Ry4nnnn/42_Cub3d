#include "cub3d.h"


void    init_data(t_cub3d *data)
{
	data->img = ft_calloc(1, sizeof(t_img_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1900, 1000, "cub3d");
	data->img->img = mlx_new_image(data->mlx, 1920, 1080);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, \
                                &data->img->line_length, &data->img->endian);
    // data->map_info = NULL;
}
