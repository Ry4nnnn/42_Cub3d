/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:54:22 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/13 15:30:08 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid_map(t_cub3d *data);
int	check_first_last_row(t_cub3d *data);
int	check_first_last_col(t_cub3d *data);
int	check_valid_chars(t_cub3d *data);
int	check_valid_player(t_cub3d *data);

/**
 * @brief Check the overall validity of the map.
 *
 * This function checks various aspects of the map to ensure its validity.
 * It includes checks for the first and last rows, first and last columns,
 * valid characters, and the presence of a single player starting position.
 *
 * @param data The main data structure for the application.
 * @return 1 if the map is invalid, 0 if it is valid.
 */
int	check_valid_map(t_cub3d *data)
{
	if (check_first_last_row(data))
		return (1);
	if (check_first_last_col(data))
		return (1);
	if (check_valid_chars(data))
		return (1);
	if (check_valid_player(data))
		return (1);
	return (0);
}

/**
 * @brief Check if the first and last rows of the map are closed.
 *
 * This function checks if the first and last rows of the map contain '0'
 * indicating an unclosed map boundary.
 *
 * @param data The main data structure for the application.
 * @return 1 if the first or last rows are not closed, 0 otherwise.
 */
int	check_first_last_row(t_cub3d *data)
{
	int	i;
	int	r;

	i = -1;
	while (data->texture->map[0][++i])
	{
		r = is_wall(data, i, 0);
		if (r != 0 && r != 4)
		{
			ft_putstr_fd("Error: Map first or last rows not closed\n", 2);
			return (1);
		}
	}
	i = -1;
	while (data->texture->map[data->texture->height - 1][++i])
	{
		r = is_wall(data, i, data->texture->height - 1);
		if (r != 0 && r != 4)
		{
			ft_putstr_fd("Error: Map first or last rows not closed\n", 2);
			return (1);
		}
	}
	return (0);
}

/**
 * @brief Check if the first and last columns of the map are closed.
 *
 * This function checks if the first and last columns of the map contain '0'
 * indicating an unclosed map boundary.
 *
 * @param data The main data structure for the application.
 * @return 1 if the columns are not closed, 0 otherwise.
 */
int	check_first_last_col(t_cub3d *data)
{
	int	i;

	i = -1;
	while (++i < data->texture->height)
	{
		if (data->texture->map[i][0] == '0' \
			|| data->texture->map[i][data->texture->width - 1] == '0')
		{
			ft_putstr_fd("Error: Map columns not closed\n", 2);
			return (1);
		}
	}
	return (0);
}

/**
 * @brief Check if the map contains valid characters.
 *
 * This function iterates through the map and checks if each character is valid.
 * It also counts the number of player starting positions.
 *
 * @param data The main data structure for the application.
 * @return 1 if there is an invalid character in the map, 0 otherwise.
 */
int	check_valid_chars(t_cub3d *data)
{
	int	i;
	int	j;
	int	w;

	data->texture->flag = 0;
	i = -1;
	while (++i < data->texture->height)
	{
		j = -1;
		while (++j < data->texture->width)
		{
			w = is_wall(data, j, i);
			if (w == 1)
			{
				ft_putstr_fd("Error: Invalid character in map\n", 2);
				return (1);
			}
			if (w == 2)
				data->texture->flag++;
		}
	}
	return (0);
}

/**
 * @brief Check if there is a valid number of player starting positions.
 *
 * This function checks if there is exactly one player starting position 
 * in the map.
 *
 * @param data The main data structure for the application.
 * @return 1 if the number of players is not valid, 0 otherwise.
 */
int	check_valid_player(t_cub3d *data)
{
	if (data->texture->flag != 1)
	{
		ft_putstr_fd("Error: Invalid number of players\n", 2);
		return (1);
	}
	return (0);
}
