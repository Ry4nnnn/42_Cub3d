/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:07:43 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/13 13:39:53 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_resize(t_cub3d *data);
int		check_map(t_cub3d *data);
int		check_up_down_left_right(t_cub3d *data, int x, int y);
void	assign_player_direction(t_cub3d *data, int x, int y);

/**
 * @brief Resize the map to ensure all rows have the same width.
 *
 * This function resizes the map to ensure that all rows have the same width.
 *
 * @param data The main data structure for the application.
 */
void	map_resize(t_cub3d *data)
{
	int		w;
	int		i;
	int		j;
	char	*tmp;

	w = data->texture->width;
	i = -1;
	while (++i < data->texture->height)
	{	
		if (ft_strlen(data->texture->map[i]) < w)
		{
			tmp = data->texture->map[i];
			data->texture->map[i] = ft_calloc(w + 1, sizeof(char));
			ft_strlcpy(data->texture->map[i], tmp, ft_strlen(tmp) + 1);
			j = ft_strlen(tmp);
			while (j < w)
			{
				data->texture->map[i][j] = ' ';
				j++;
			}
			data->texture->map[i][j] = '\0';
			free (tmp);
		}
	}
}

/**
 * @brief Check the map for invalid configurations.
 *
 * This function checks the map for invalid configurations, such as players
 * next to walls and ensures the map is properly closed.
 *
 * @param data The main data structure for the application.
 * @return 1 if an error occurs, 0 otherwise.
 */
int	check_map(t_cub3d *data)
{
	int		i;
	int		j;
	int		w;

	i = -1;
	while (++i < data->texture->height)
	{
		j = -1;
		while (++j < data->texture->width)
		{
			w = is_wall(data, j, i);
			if (w == 2 || w == 3)
			{
				if (check_up_down_left_right(data, i, j))
					return (1);
			}
			if (w == 2)
				assign_player_direction(data, i, j);
		}
	}
	return (0);
}

/**
 * @brief Check if the player is next to a wall.
 *
 * This function checks if the player is next to a wall.
 *
 * @param data The main data structure for the application.
 * @param i The x coordinate of the player.
 * @param j The y coordinate of the player.
 * @return 1 if an error occurs, 0 otherwise.
 */
int	check_up_down_left_right(t_cub3d *data, int i, int j)
{
	char	**map;

	map = data->texture->map;
	if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ' \
		|| map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
	{
		ft_putstr_fd("Error: Invalid Map\n", 2);
		return (1);
	}
	return (0);
}

/**
 * @brief Assign direction based on a given character.
 *
 * This function assigns a direction based on a given character.
 *
 * @param data The main data structure for the application.
 * @param x The x coordinate of the player.
 * @param y The y coordinate of the player.
 * @return 0 if successful, otherwise 1.
 */
void	assign_player_direction(t_cub3d *data, int i, int j)
{
	int	dir;

	if (data->texture->map[i][j] == 'N')
		dir = NORTH;
	else if (data->texture->map[i][j] == 'S')
		dir = SOUTH;
	else if (data->texture->map[i][j] == 'E')
		dir = EAST;
	else if (data->texture->map[i][j] == 'W')
		dir = WEST;
	else
		return ;
	init_player_data(data, j, i, dir);
}
