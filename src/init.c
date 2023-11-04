#include "cub3d.h"


void    init_data(t_cub3d *data)
{
	data->img = ft_calloc(1, sizeof(t_img_data));
    data->map_info = NULL;
    data->px = 100;
	data->py = 100;
}
