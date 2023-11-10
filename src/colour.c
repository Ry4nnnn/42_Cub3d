#include "cub3d.h"

void	drawLine(t_cub3d	*data, int x1, int y1, int x2, int y2, int colour);

void    half_window(t_cub3d *data, int colour1, int colour2)
{
	t_image	*img_info;

    img_info = ft_calloc(1, sizeof(t_image));
	img_info->start_x = 0;
	img_info->start_y = 0;
	img_info->dest_x = SIZE_X;
	img_info->dest_y = SIZE_Y / 2;
	img_info->colour = colour1;
	change_colour(data, img_info);
	img_info->start_x = 0;
	img_info->start_y = SIZE_Y / 2;
	img_info->dest_x = SIZE_X;
	img_info->dest_y = SIZE_Y;
	img_info->colour = colour2;
	change_colour(data, img_info);
}

void    change_colour(t_cub3d *data, t_image *img)
{
    int i;
    int j;

    j = img->start_y - 1;
    while (++j <= img->dest_y)
    {
        i = img->start_x - 1;
        while (++i <= img->dest_x)
           my_mlx_pixel_put(data, i, j, img->colour);
    }
}

void    drawPlayer(t_cub3d	*data)
{
    int i;
    int j;
	int	dx;
	int	dy;

    j = data->player->py - 1;
    while (++j <= data->player->py + 8)
    {
        i = data->player->px - 1;
        while (++i <= data->player->px + 8)
            my_mlx_pixel_put(data, i, j, 0x00B9C781);
    }
	i = -1;
	while (++i < 50)
	{
		dx = i * (data->player->dirx);
		dy = i * (data->player->diry);
		my_mlx_pixel_put(data, data->player->px + 4 + dx, data->player->py + 4 + dy, 0x00B9C781);
	}
}

void	drawSquare(t_cub3d	*data, int x, int y, int colour)
{
	int	i;
	int	j;

	j = y - 1;
	while (++j <= y + 20)
	{
		i = x - 1;
		while (++i <= x + 20)
			my_mlx_pixel_put(data, i, j, colour);
	}
}

void    drawMap(t_cub3d	*data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map;
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '1')
				drawSquare(data, i * 22, j * 22, 0x00FFFFFF);
			else if (map[j][i] == '0')
				drawSquare(data, i * 22, j * 22, 0x00111111);
		}
	}	
}

void drawLine(t_cub3d	*data, int x1, int y1, int x2, int y2, int colour)  
{  
    int dx;
	int	dy;
	int	p;
	int	x;
	int	y;
	int	s;

    dx=ft_abs(x2-x1);
    dy=ft_abs(y2-y1);
	if (dx >= dy)
		s = dx;
	else
		s = dy;
	dx /= s;
	dy /= s;
    x=x1;  
    y=y1;  
    p = -1;
    while(++p <= s)  
	{  
        x += dx;
		y += dy;
        my_mlx_pixel_put(data, x,y,colour);
	}
}  