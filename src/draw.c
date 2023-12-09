/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:25:27 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 15:17:58 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawplayer(t_cub3d	*data);
void	drawmap(t_cub3d	*data);
int		is_wall(t_cub3d *data, int x, int y);
void	init_ray(t_cub3d *data, t_ray *ray, int x, int w);
void	drawray(t_cub3d *data);

/**
 * @brief Draw the player character on the screen.
 *
 * This function draws a square to represent the player character and a line
 * to indicate the direction the player is facing.
 *
 * @param data The main data structure for the application.
 */
void	drawplayer(t_cub3d	*data)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	data->player->px *= 22;
	data->player->py *= 22;
	j = (int)(data->player->py);
	while (++j <= (int)(data->player->py) + 8)
	{
		i = (int)(data->player->px);
		while (++i <= (int)(data->player->px) + 8)
			my_mlx_pixel_put(data, i, j, 0x00B9C781);
	}
	i = -1;
	while (++i < 20)
	{
		dx = i * (data->player->dirx);
		dy = i * (data->player->diry);
		my_mlx_pixel_put(data, (data->player->px) + 4 + dx, \
					(data->player->py) + 4 + dy, 0x00B9C781);
	}
	data->player->px /= 22;
	data->player->py /= 22;
}

/**
 * @brief Draw the map on the screen.
 *
 * This function draws the map on the screen. It consists of a grid
 * representing the walls and other elements in different colors.
 *
 * @param data The main data structure for the application.
 */
void    drawmap(t_cub3d	*data)
{
	int	i;
	int	j;
	int	r;

	j = -1;
	while (++j < 198)
	{
		i = -1;
		while (++i < 198)
			my_mlx_pixel_put(data, i, j, 0x007DC3E9);
	}
	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			r = is_wall(data, (int)(data->player->px) - 4 + i, \
				(int)(data->player->py) - 4 + j);
			if (r == 0)
				drawsquare(data, i * 22, j * 22, 0x00FFFFFF);
			else if (r == 2 || r == 3)
				drawsquare(data, i * 22, j * 22, 0x00111111);
			else
				continue ;
		}
	}
	drawsquare(data, 88, 88, 0x00E97D7D);
	r = -1;
	while (++r < 25)
	{
		i = r * (data->player->dirx);
		j = r * (data->player->diry);
		my_mlx_pixel_put(data, 88 + 10 + i, 88 + 10 + j, 0x00E97D7D);
		my_mlx_pixel_put(data, 88 + 11 + i, 88 + 11 + j, 0x00E97D7D);
		my_mlx_pixel_put(data, 88 + 12 + i, 88 + 12 + j, 0x00E97D7D);
	}
}

/**
 * @brief Check if a given position is a wall or other element.
 *
 * This function checks if a given position in the map is a wall or another
 * type of element. It returns different values based on the content of the
 * map at the specified position.
 *
 * @param data The main data structure for the application.
 * @param x The x-coordinate of the position.
 * @param y The y-coordinate of the position.
 * @return 0 if the position is an open space, 1 if out of bounds, 
 * 2 if the position is a wall or other element, 3 for other cases.
 */
int	is_wall(t_cub3d *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->texture->width \
		|| y >= data->texture->height)
		return (1);
	if (data->texture->map[y][x] == '1')
		return (0);
	else if (data->texture->map[y][x] == 'N' \
			|| data->texture->map[y][x] == 'S' \
			|| data->texture->map[y][x] == 'E' \
			|| data->texture->map[y][x] == 'W')
		return (2);
	else if (data->texture->map[y][x] == '0')
		return (3);
	else if (data->texture->map[y][x] == ' ')
		return (4);
	else
		return (1);
}

/**
 * @brief Initialize ray parameters for a specific column in the screen.
 *
 * This function initializes the ray parameters based on the player's 
 * position and direction for a specific column (x-coordinate) 
 * in the screen.
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
	ray->dx = sqrt(1 + (ray->raydiry * ray->raydiry) \
			/ (ray->raydirx * ray->raydirx));
	ray->dy = sqrt(1 + (ray->raydirx * ray->raydirx) \
			/ (ray->raydiry * ray->raydiry));
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->xo = (data->player->px - ray->mx) * ray->dx;
	}
	else
	{
		ray->stepx = 1;
		ray->xo = (ray->mx + 1.0 - data->player->px) * ray->dx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->yo = (data->player->py - ray->my) * ray->dy;
	}
	else
	{
		ray->stepy = 1;
		ray->yo = (ray->my + 1.0 - data->player->py) * ray->dy;
	}
}

/**
 * @brief Draw a texture on the screen.
 *
 * This function draws a texture on the screen based on the ray parameters.
 *
 * @param data The main data structure for the application.
 * @param x The x-coordinate of the screen column.
 */
void	draw_texture(t_cub3d *data, int x)
{
	t_coord	wall;
	t_coord	draw;
	int		wall_index;
	double	wall_hit;
	char	*dest;

	if (data->ray->side == 0)
	{
		wall_hit = (data->player->py + \
					data->ray->perpwalldist * (data->ray->raydiry));
	}
	else
	{
		wall_hit = (data->player->px + \
					data->ray->perpwalldist * (data->ray->raydirx));
	}
	wall_hit -= floor(wall_hit);
	draw.x = x;
	draw.y = data->ray->drawstart - 1;
	while (++draw.y <= data->ray->drawend)
	{
		wall.x = (int)(wall_hit * data->current_texture->width);
		wall.y = (int)(((double)((draw.y - data->ray->drawstart)) / \
					(double)data->ray->lineheight) \
					* data->current_texture->width);
		wall_index = wall.x * (data->current_texture->bpp / 8) \
					+ wall.y * data->current_texture->line_length;
		dest = data->current_texture->addr + wall_index;
		my_mlx_pixel_put(data, SIZE_X - draw.x, draw.y, *(unsigned int *)dest);
	}
}

/**
 * @brief Perform raycasting and draw the resulting image.
 *
 * This function performs raycasting for each column in the screen and 
 * draws the resulting image.
 *
 * @param data The main data structure for the application.
 */
void	drawray(t_cub3d *data)
{
	t_ray	*ray;
	int		i;
	int		w;

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
		{
			data->current_texture = (ray->north_south == NORTH) ? data->texture->north : data->texture->south;
		}
		if (ray->east_west != -1)
		{
			data->current_texture = (ray->east_west == EAST) ? data->texture->east : data->texture->west;
		}
		draw_texture(data, i);
	}	
}
