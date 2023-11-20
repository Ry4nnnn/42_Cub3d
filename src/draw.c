#include "cub3d.h"

void    drawPlayer(t_cub3d	*data)
{
	int i;
	int j;
	int	dx;
	int	dy;

	data->player->px *= 22;
	data->player->py *= 22;
	j = (int)(data->player->py);
	while (++j <= (int)(data->player->py) + 8)
	{
		i = (int)(data->player->px);
		while (++i <= (int)(data->player->px)+ 8)
			my_mlx_pixel_put(data, i, j, 0x00B9C781);
	}
	i = -1;
	while (++i < 50)
	{
		dx = i * (data->player->dirx);
		dy = i * (data->player->diry);
		my_mlx_pixel_put(data, (data->player->px) + 4 + dx, (data->player->py) + 4 + dy, 0x00B9C781);
	}
	data->player->px /= 22;
	data->player->py /= 22;
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
			else if (map[j][i] == '0' || map[j][i] == 'N')
				drawSquare(data, i * 22, j * 22, 0x00111111);
		}
	}	
}

int	is_wall(t_cub3d *data, int x, int y)
{
	// printf("map width: %i, map height: %i\n", data->map_width, data->map_height *);
	if (x < 0 || y < 0 || x >= data->map_width|| y >= data->map_height)
		return (1);
	if (data->map[y][x] == '1')
		return (0);
	return (1);
}

// void    drawRay(t_cub3d *data)
// {
// 	// int	 	r;
// 	int		dof;
// 	float   atan;
// 	float	rx;
// 	float	ry;
// 	float	ra;
// 	// float	vx;
// 	// float	vy;
// 	float	adjacent;
// 	float	opposite;
// 	float	stepx;
// 	float	stepy;
// 	float   dist_h;
// 	float   dist_v;
// 	// double	final_dist;
// 	// double  final_scale;
// 	// int		final_side;
// 	int     i;
// 	int     w;

// 	i = -1;
// 	w = 1;
// 	// ra = data->player->pa;
// 	if (data->player->pa >= 360)
// 		data->player->pa -= 360;
// 	else if (data->player->pa < 0)
// 		data->player->pa += 360;
// 	while (++i < w)
// 	{
// 		// Check horizontal line ray
// 		dof = 0;
// 		atan = 1 / tan(data->player->pa * PI / 180);
// 		if (data->player->pa > 0 && data->player->pa < 180) // looking up
// 		{
// 			printf("looking up\n");
// 			ry = floor(data->player->py)  - 0.0001;
// 			opposite = data->player->py - ry;
// 			rx = data->player->px + opposite * atan;
// 			stepy = -1;
// 			stepx = -stepy * atan;

// 		}
// 		else if (data->player->pa > 180 && data->player->pa < 360) // looking down
// 		{
// 			printf("looking down\n");
// 			ry = floor(data->player->py) + 1.0001;
// 			opposite = ry - data->player->py;
// 			rx = data->player->px + opposite * atan;
// 			stepy = 1;
// 			stepx = -stepy * atan;
// 		}
// 		else
// 		{
// 			rx = data->player->px;
// 			ry = data->player->py;
// 			dof = 20;
// 		}
// 		printf("stepx: %f, stepy: %f, rx %f, ry %f\n", stepx, stepy, rx, ry);
// 		dist_h = 100000000;
// 		while (dof < 20)
// 		{
// 			if (is_wall(data, (int)(rx), (int)(ry)) == 0)
// 			{
// 				printf("it's a wall\n");
// 				dist_h = sqrt((data->player->px - rx) * (data->player->px - rx) + (data->player->py - ry) * (data->player->py - ry));
// 				dof = 20;
// 			}
// 			else
// 			{
// 				rx += stepx;
// 				ry += stepy;
// 				dof++;
// 			}
// 		}
// 		printf("rx: %f, ry: %f, px %f, py %f, pa %i\n", rx, ry, data->player->px, data->player->py, data->player->pa);
// 		(void)dist_h;
// 		(void)dist_v;
// 		(void)ra;
// 		(void)adjacent;
// 		(void)opposite;
// 		(void)stepx;
// 		(void)stepy;
// 		(void)dof;
// 		// vx = rx;
// 		// vy = ry;
// 		// // Check vertical line ray
// 		// dof = 0;
// 		// atan = tan(data->player->pa * PI / 180);
// 		// if (data->player->pa > (PI / 2) && data->player->pa < (3 * PI / 2))
// 		// {
// 		// 	rx = floor(data->player->px) - 0.0001;
// 		// 	adjacent = data->player->px - rx;
// 		// 	ry = data->player->py + adjacent * atan;
// 		// 	stepx = -1;
// 		// 	stepy = -stepx * atan;
// 		// }
// 		// else if (data->player->pa < (PI / 2) || data->player->pa > (3 * PI / 2))
// 		// {
// 		// 	rx = floor(data->player->px) + 1.0001;
// 		// 	adjacent = rx - data->player->px;
// 		// 	ry = data->player->py + adjacent * atan;
// 		// 	stepx = 1;
// 		// 	stepy = -stepx * atan;
// 		// }
// 		// else
// 		// {
// 		// 	rx = data->player->px;
// 		// 	ry = data->player->py;
// 		// 	dof = 8;
// 		// }
// 		// dist_v = 100000000;
// 		// while (dof < 8)
// 		// {
// 		// 	if (is_wall(data, (int)(rx), (int)(ry)) == 0)
// 		// 	{
// 		// 		dist_v = sqrt((data->player->px - rx) * (data->player->px - rx) + (data->player->py - ry) * (data->player->py - ry));
// 		// 		dof = 8;
// 		// 	}
// 		// 	else
// 		// 	{
// 		// 		rx += stepx;
// 		// 		ry += stepy;
// 		// 		dof++;
// 		// 	}
// 		// }
// 		// (void)dist_h;
// 		// (void)dist_v;
// 		// (void)final_dist;
// 		// (void)final_side;
// 		// (void)final_scale;
// 		// (void)ra;
// 		// (void)r;
// 		// // compare distance of horizontal and vertical rays
// 		// if (dist_v < dist_h)
// 		// {
// 		// 	final_dist = dist_v;
// 		// 	final_side = 0;
// 		// }
// 		// else
// 		// {
// 		// 	final_dist = dist_h;
// 		// 	final_side = 1;
// 		// }
		
// 	}

// }

void	init_ray(t_cub3d *data, t_ray *ray, int x, int w)
{
	double	scale;

	scale = 2 * x / (double)w - 1;
	ray->raydirx = data->player->dirx + data->player->planex * scale;
	ray->raydiry = data->player->diry + data->player->planey * scale;
	ray->mx = (int)data->player->px;
	ray->my = (int)data->player->py;
	ray->dx = (ray->raydirx == 0) ? 1e30 : ft_abs(1 / ray->raydirx);
	ray->dy = (ray->raydiry == 0) ? 1e30 : ft_abs(1 / ray->raydiry);
	ray->stepx = ray->raydirx < 0 ? -1 : 1;
	ray->xo = ray->raydirx < 0 ? data->player->px - ray->mx : ray->mx + 1.0 - data->player->px;
	ray->stepy = ray->raydiry < 0 ? -1 : 1;
	ray->yo = ray->raydiry < 0 ? data->player->py - ray->my : ray->my + 1.0 - data->player->py;
}

void	drawRay(t_cub3d *data)
{
	int		hit;
	int		side;
	int		i;
	int		w;

	i = -1;
	w = 600;
	while (++i < w)
	{
		init_ray(data, data->player->ray, i, w);
		hit = 0;
		while (hit == 0)
		{
			if (data->player->ray->xo < data->player->ray->yo)
			{
				data->player->ray->xo += data->player->ray->dx;
				data->player->ray->mx += data->player->ray->stepx;
				side = 0;
			}
			else
			{
				data->player->ray->yo += data->player->ray->dy;
				data->player->ray->my += data->player->ray->stepy;
				side = 1;
			}
			if (is_wall(data, data->player->ray->mx, data->player->ray->my) == 0)
				hit = 1;
		}
		if (side == 0)
			data->player->ray->perpwalldist = data->player->ray->xo - data->player->ray->dx;
		else
			data->player->ray->perpwalldist = data->player->ray->yo - data->player->ray->dy;
		data->player->ray->lineheight = (int)(SIZE_Y / data->player->ray->perpwalldist);
		data->player->ray->drawstart = -data->player->ray->lineheight / 2 + SIZE_Y / 2;
		if (data->player->ray->drawstart < 0)
			data->player->ray->drawstart = 0;
		data->player->ray->drawend = data->player->ray->lineheight / 2 + SIZE_Y / 2;
		if (data->player->ray->drawend >= SIZE_Y)
			data->player->ray->drawend = SIZE_Y - 1;
	}
}

void	drawWall(t_cub3d *data)
{
	
}