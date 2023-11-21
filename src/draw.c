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

	ray->east_west = -1;
	ray->north_south = -1;
	scale = 2 * x / (double)w - 1;
	ray->raydirx = data->player->dirx + data->player->planex * scale;
	ray->raydiry = data->player->diry + data->player->planey * scale;
	ray->mx = (int)data->player->px;
	ray->my = (int)data->player->py;
	ray->dx = sqrt(1 + (ray->raydiry * ray->raydiry) / (ray->raydirx * ray->raydirx));
	ray->dy = sqrt(1 + (ray->raydirx * ray->raydirx) / (ray->raydiry * ray->raydiry));
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->xo = (data->player->px - ray->mx) * ray->dx;
		ray->east_west = 3;
	}
	else
	{
		ray->stepx = 1;
		ray->xo = (ray->mx + 1.0 - data->player->px) * ray->dx;
		ray->east_west = 2;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->yo = (data->player->py - ray->my) * ray->dy;
		ray->north_south = 0;
	}
	else
	{
		ray->stepy = 1;
		ray->yo = (ray->my + 1.0 - data->player->py) * ray->dy;
		ray->north_south = 1;
	}
}


void	drawRay(t_cub3d *data)
{
	t_ray	*ray;
	int		i;
	int		w;
	int		colour;
	int		j;

	i = -1;
	w = SIZE_X;
	ray = data->player->ray;
	while (++i < w)
	{
		init_ray(data, ray, i, w);
		ray->hit = 0;
		while (ray->hit == 0)
		{
			if (ray->xo < ray->yo)
			{
				ray->xo += ray->dx;
				ray->mx += ray->stepx;
				ray->side = 0;
			}
			else
			{
				ray->yo += ray->dy;
				ray->my += ray->stepy;
				ray->side = 1;
			}
			if (is_wall(data, ray->mx, ray->my) == 0)
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->perpwalldist = ray->xo - ray->dx;
		else
			ray->perpwalldist = ray->yo - ray->dy;
		ray->perpwalldist *= cos(ray->raydirx - data->player->dirx);
		ray->lineheight = (int)(SIZE_Y / ray->perpwalldist);
		ray->drawstart = -ray->lineheight / 2 + SIZE_Y / 2;
		if (ray->drawstart < 0)
			ray->drawstart = 0;
		ray->drawend = ray->lineheight / 2 + SIZE_Y / 2;
		if (ray->drawend >= SIZE_Y)
			ray->drawend = SIZE_Y - 1;
		if (ray->north_south != -1)
		{
			if (ray->north_south == 0)
				colour = RED;
			if (ray->north_south == 1)
				colour = BLUE;
		}
		if (ray->east_west != -1)
		{
			if (ray->east_west == 2)
				colour = GREEN;
			if (ray->east_west == 3)
				colour = ORANGE;
		}
		j = ray->drawstart - 1;
		while (++j <= ray->drawend)
			my_mlx_pixel_put(data, i, j, colour);
	}
}

// void	drawWall(t_cub3d *data)
// {
// 	t_ray	*ray;
// 	int		colour;

// 	ray = data->player->ray;
// 	if (ray->side == 0)
// 		colour = RED;
// 	else
// 		colour = BLUE;
// 	drawLine(data, 0, ray->drawstart, SIZE_X, ray->drawstart, colour);
// }