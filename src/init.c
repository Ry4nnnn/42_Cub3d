#include "cub3d.h"


void    init_data(t_cub3d *data)
{
    data->map_info = NULL;
    data->player = ft_calloc(1, sizeof(t_player));
    data->player->px = 26.25;
	data->player->py = 11.25;
    data->player->dirx = -1;
    data->player->diry =  0;
    data->player->planex = 0;
    data->player->planey = 0.45;
    data->player->t = 0;
    data->player->old_t = 0;
    data->player->ray = ft_calloc(1, sizeof(t_ray));
}
