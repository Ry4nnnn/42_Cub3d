/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:56:32 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 17:04:43 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_fc_color(t_cub3d *data, char *str);
int	init_floor(t_cub3d *data, char **array, char **num);
int	init_ceiling(t_cub3d *data, char **array, char **num);

/**
 * @brief Initialize floor and ceiling colors based on a given string.
 *
 * This function initializes floor and ceiling colors based on a string
 * representing a line from the configuration file. It handles the 'F' and 'C'
 * options, parsing RGB values and converting them to hexadecimal colors.
 *
 * @param data The main data structure for the application.
 * @param str The string representing a line from the configuration file.
 * @return 1 if an error occurs, 0 otherwise.
 */
int	init_fc_color(t_cub3d *data, char *str)
{
	char	**array;
	char	**num;

	array = ft_split(str, ' ');
	num = ft_split(array[1], ',');
	if (!ft_strncmp(str, "F ", 2))
	{
		if (init_floor(data, array, num))
			return (1);
	}
	else if (!ft_strncmp(str, "C ", 2))
	{
		if (init_ceiling(data, array, num))
			return (1);
	}
	else
		return (1);
	return (0);
}

int	init_floor(t_cub3d *data, char **array, char **num)
{
	int		i;

	i = -1;
	while (num[++i])
	{
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
		{
			free_2d(array);
			free_2d(num);
			return (1);
		}
	}
	data->texture->floor = \
	rgb_to_hex(ft_atoi(num[0]), ft_atoi(num[1]), ft_atoi(num[2]));
	free_2d(array);
	free_2d(num);
	return (0);
}

int	init_ceiling(t_cub3d *data, char **array, char **num)
{
	int		i;

	i = -1;
	while (num[++i])
	{
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
		{
			free_2d(array);
			free_2d(num);
			return (1);
		}
	}
	data->texture->ceiling = \
	rgb_to_hex(ft_atoi(num[0]), ft_atoi(num[1]), ft_atoi(num[2]));
	free_2d(array);
	free_2d(num);
	return (0);
}