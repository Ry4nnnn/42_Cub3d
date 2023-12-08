#include "cub3d.h"

void	drawPlayer(t_cub3d	*data);
void    drawMap(t_cub3d	*data);
int		is_wall(t_cub3d *data, int x, int y);
void	init_ray(t_cub3d *data, t_ray *ray, int x, int w);
void	drawRay(t_cub3d *data);

/**
 * @brief Draw the player character on the screen.
 *
 * This function draws a square to represent the player character and a line
 * to indicate the direction the player is facing.
 *
 * @param data The main data structure for the application.
 */
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
	while (++i < 20)
	{
		dx = i * (data->player->dirx);
		dy = i * (data->player->diry);
		my_mlx_pixel_put(data, (data->player->px) + 4 + dx, (data->player->py) + 4 + dy, 0x00B9C781);
	}
	data->player->px /= 22;
	data->player->py /= 22;
}

/**
 * @brief Draw the map on the screen.
 *
 * This function draws a grid representing the map, with different colors for walls,
 * open spaces, and the player's position.
 *
 * @param data The main data structure for the application.
 */
// void    drawMap(t_cub3d	*data)
// {
// 	char	**map;
// 	int		i;
// 	int		j;

// 	int		x;
// 	int		y;

// 	int		dx;
// 	int		dy;

// 	map = data->texture->map;
// 	j = -1;
// 	while(++j < 198)
// 	{
// 		i = -1;
// 		while (++i < 198)
// 			my_mlx_pixel_put(data, i, j, 0x007DC3E9);	
// 	}
// 	i = 0;
// 	x = (int)(data->player->px) - 4;
// 	{
// 		x++;
// 		i += 22;
// 	}
// 	printf("width: %d\n", data->texture->width);
// 	printf("height: %d\n", data->texture->height);
// 	while (i < 198)
// 	{
// 		j = 0;
// 		y = (int)(data->player->py) - 4;
// 		while (y < 0)
// 		{
// 			y++;
// 			j += 22;
// 		}
// 		while (j < 198)
// 		{
// 			printf("x: %d, y: %d\n", x, y);
// 			if (x >= data->texture->width || y >= data->texture->width || x < 0 || y < 0)
// 				break;
// 			if (map[y][x] == '1')
// 				drawSquare(data, i, j, 0x00FFFFFF);
// 			else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W') 
// 				drawSquare(data, i, j, 0x00111111);
// 			j += 22;
// 			y++;
// 		}
// 		i += 22;
// 		x++;
// 	}
// 	drawSquare(data, 88, 88, 0x00E97D7D);
// 	i = -1;
// 	while (++i < 25)
// 	{
// 		dx = i * (data->player->dirx);
// 		dy = i * (data->player->diry);
// 		my_mlx_pixel_put(data, 88 + 10+ dx, 88 + 10 + dy, 0x00E97D7D);
// 		my_mlx_pixel_put(data, 88 + 11 + dx, 88 + 11 + dy, 0x00E97D7D);
// 		my_mlx_pixel_put(data, 88 + 12 + dx, 88 + 12 + dy, 0x00E97D7D);
	
// 	}
// 	(void)map;
// 	(void)x;
// 	(void)y;
// 	(void)dx;
// 	(void)dy;
// }

/**
 * @brief Check if a position in the map is a wall.
 *
 * This function checks if the specified position (x, y) in the map is a wall.
 *
 * @param data The main data structure for the application.
 * @param x The x-coordinate of the position.
 * @param y The y-coordinate of the position.
 * @return 0 if the position is not a wall, 1 otherwise.
 */
int	is_wall(t_cub3d *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->texture->width || y >= data->texture->height)
		return (1);
	if (data->texture->map[y][x] == '1')
		return (0);
	return (1);
}

// unsigned int	get_color(t_cub3d *data, int x, int y)
// {
// 	char	*dst;

// 	if (x < 0 || y < 0 || x >= data->news->north->width || y >= data->news->north->height)
// 		return (0);
// 	dst = data->news->north->addr + (y * data->news->north->line_length + x * (data->news->north->bpp / 8));
// 	return (*(unsigned int*)dst);
// }

// unsigned int	texture_pixel_color(t_cub3d *data, t_ray *ray)
// {
// 	double	pixel_x;
// 	double	pixel_y;
// 	int		top;
// 	int		result;

// 	top = (ray->drawend - ray->drawstart) - (ray->lineheight / 2);
// 	pixel_x = data->player->px * data->news->north->width;
// 	printf("pixel_x %f\n", pixel_x);
// 	pixel_y = (data->player->py - top) / ray->lineheight;
// 	pixel_y *= data->texture->north->height;
// 	printf("pixel_y %f\n", pixel_y);
// 	result = get_color(data, (int)pixel_x, (int)pixel_y);
// 	printf("result %d\n", result);
// 	(void)pixel_x;
// 	(void)top;
// 	(void)pixel_y;
// 	(void)result;
// 	return (RED);
// }

/**
 * @brief Initialize ray parameters for a specific column in the screen.
 *
 * This function initializes the ray parameters based on the player's position and direction
 * for a specific column (x-coordinate) in the screen.
 *
 * @param data The main data structure for the application.
 * @param ray The ray structure to be initialized.
 * @param x The x-coordinate of the screen column.
 * @param w The total width of the screen.
 */
void	init_ray(t_cub3d *data, t_ray *ray, int x, int w)
{
	double	scale;

	ray->north_south = -1;
	ray->east_west = -1;
	scale = 2 * x / (double)w - 1;
	ray->raydirx = data->player->dirx + data->player->planex * scale;
	ray->raydiry = data->player->diry + data->player->planey * scale;
	ray->mx = (int)data->player->px;
	ray->my = (int)data->player->py;
	ray->dx = sqrt(1 + (ray->raydiry * ray->raydiry) / (ray->raydirx * ray->raydirx));
	ray->dy = sqrt(1 + (ray->raydirx * ray->raydirx) / (ray->raydiry * ray->raydiry));
	ray->stepx = (ray->raydirx < 0) ? -1 : 1;
	ray->xo = (ray->raydirx < 0) ? (data->player->px - ray->mx) * ray->dx : (ray->mx + 1.0 - data->player->px) * ray->dx;
	ray->stepy = (ray->raydiry < 0) ? -1 : 1;
	ray->yo = (ray->raydiry < 0) ? (data->player->py - ray->my) * ray->dy : (ray->my + 1.0 - data->player->py) * ray->dy;
}

/**
 * @brief Perform raycasting and draw the resulting image.
 *
 * This function performs raycasting for each column in the screen and draws the resulting image.
 *
 * @param data The main data structure for the application.
 */
void	drawRay(t_cub3d *data)
{
	t_ray	*ray;
	int		i;
	int		w;
	int		colour;
	int		j;

	i = -1;
	w = SIZE_X;
	ray = data->ray;
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
		if (ray->side == 0)
			ray->east_west = (ray->stepx == 1) ? EAST : WEST;
		else
			ray->north_south = (ray->stepy == 1) ? SOUTH : NORTH;
		if (ray->north_south != -1)
			colour = (ray->north_south == NORTH) ? RED : BLUE;
		if (ray->east_west != -1)
			colour = (ray->east_west == EAST) ? GREEN : ORANGE;
		// if (ray->north_south == NORTH)
		// {
		// 	j = ray->drawstart - 1;
		// 	while (++j <= ray->drawend)
		// 		my_mlx_pixel_put(data, i, j, (int)texture_pixel_color(data, ray));	
		// }
		// else
		// {
			j = ray->drawstart - 1;
			while (++j <= ray->drawend)
				my_mlx_pixel_put(data, SIZE_X - i , j, colour);
		// }
			
	}
}