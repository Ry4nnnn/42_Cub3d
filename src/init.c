#include "cub3d.h"


void    init_data(t_cub3d *data)
{
	data->img = ft_calloc(1, sizeof(t_img_data));
    data->map_info = NULL;
    data->player = ft_calloc(1, sizeof(t_player));
    data->player->px = 20;
	data->player->py = 20;
    data->player->pa = 0;
    data->player->pdx = 10 * sin(data->player->pa);
	data->player->pdy = 10 * cos(data->player->pa);
    data->player->dirx = -1;
    data->player->diry = 0;
    data->player->planex = 0;
    data->player->planey = 0.66;
    data->player->t = 0;
    data->player->old_t = 0;
}
