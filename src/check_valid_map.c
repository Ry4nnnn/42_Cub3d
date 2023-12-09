/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:54:22 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 18:12:09 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_valid_map(t_cub3d *data);
int	check_first_last_row(t_cub3d *data);
int	check_first_last_col(t_cub3d *data);
int	check_valid_chars(t_cub3d *data);
int	check_valid_player(t_cub3d *data);

/**
 * @brief Check if the map is valid.
 *
 * This function checks if the map is valid, ensuring that it contains
 * valid characters, is closed, and has only one player.
 *
 * @param data The main data structure for the application.
 * @return 1 if an error occurs, 0 otherwise.
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

int	check_first_last_row(t_cub3d *data)
{
	if (ft_strchr(data->texture->map[0], '0') \
		|| ft_strchr(data->texture->map[data->texture->height - 1], '0'))
	{
		ft_putstr_fd("Error: Map first or last rows not closed\n", 2);
		return (1);
	}
	return (0);
}

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

int	check_valid_player(t_cub3d *data)
{
	if (data->texture->flag != 1)
	{
		ft_putstr_fd("Error: Invalid number of players\n", 2);
		return (1);
	}
	return (0);
}
