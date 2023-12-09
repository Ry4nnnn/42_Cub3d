/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:30:47 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:35:20 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_file_data(t_cub3d *data, char **array);
int	init_file_data_texture(t_cub3d *data, char **array);
int	init_file_data_floor_ceiling(t_cub3d *data, char **array);
int	init_file_data_map(t_cub3d *data, char **array);
int	init_map_layout(t_cub3d *data, char **array, int i);

/**
 * @brief Initialize data from a file.
 *
 * This function reads an array of strings, typically representing lines
 * from a configuration file, and initializes various components of the
 * t_cub3d structure, including textures and color settings.
 *
 * @param data The main data structure for the application.
 * @param array An array of strings representing lines from the file.
 * @return 1 if an error occurs during initialization, 0 otherwise.
 */
int	init_file_data(t_cub3d *data, char **array)
{
	if (init_file_data_texture(data, array) == 1)
		return (1);
	if (init_file_data_floor_ceiling(data, array) == 1)
		return (1);
	if (init_file_data_map(data, array) == 1)
		return (1);
	return (0);
}

/**
 * @brief Initialize map-related data.
 *
 * This function checks and initializes map-related data by calling the
 * `init_file_data` function. It processes an array of strings representing
 * lines from a configuration file.
 *
 * @param data The main data structure for the application.
 * @param array An array of strings representing lines from the file.
 * @return 1 if an error occurs during initialization, 0 otherwise.
 */
int	init_file_data_map(t_cub3d *data, char **array)
{
	int	i;
	int	result;

	i = 7;
	result = 0;
	while (array[i])
	{
		if (ft_strncmp(array[i], " ", 1) == 0 \
				|| ft_strncmp(array[i], "1", 1) == 0)
		{
			result = init_map_layout(data, array, i);
			break ;
		}
		else
		{
			ft_putstr_fd("Error: Invalid file format\n", 2);
			break ;
		}
		i++;
	}
	if (result == 1)
		return (1);
	return (0);
}

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
int	init_file_data_floor_ceiling(t_cub3d *data, char **array)
{
	int	i;
	int	result;

	i = 5;
	result = 0;
	while (array[i] && (i >= 5 && i <= 6))
	{
		result = init_fc_color(data, array[i]);
		if (result == 1)
		{
			ft_putstr_fd("Error: Invalid colour\n", 2);
			break ;
		}
		i++;
	}
	if (result == 1)
		return (1);
	return (0);
}

/**
 * @brief Initialize texture data based on a given string.
 *
 * This function initializes texture data structures based on a string
 * representing a line from the configuration file. It handles different
 * types of textures, such as north, south, west, east, and door textures.
 *
 * @param data The main data structure for the application.
 * @param array An array of strings representing lines from the file.
 * @return 1 if an error occurs, 0 otherwise.
 */
int	init_file_data_texture(t_cub3d *data, char **array)
{
	int	i;
	int	result;

	i = 0;
	while (array[i] && (i >= 0 && i <= 4))
	{
		if (i >= 0 && i <= 4)
		{
			result = init_textures(data, array[i]);
			if (result == 1)
			{
				ft_putstr_fd("Error: Invalid texture\n", 2);
				break ;
			}
		}
		i++;
	}
	if (result == 1)
		return (1);
	return (0);
}

/**
 * @brief Initialize the map layout based on a given string array.
 *
 * This function processes the array of strings representing the map layout
 * and initializes the height, width, and content of the map in the t_cub3d 
 * structure.
 *
 * @param data The main data structure for the application.
 * @param array An array of strings representing lines from the file.
 * @param i The starting index in the array for processing the map layout.
 * @return 0 if successful, 1 if an error occurs.
 */
int	init_map_layout(t_cub3d *data, char **array, int i)
{
	int	j;
	int	width;

		j = i;
	while (array[j])
		j++;
	data->texture->height = j - i;
	width = ft_strlen(array[i]);
	data->texture->map = ft_calloc(j - i + 1, sizeof(char *));
	j = -1;
	while (array[i])
		data->texture->map[++j] = ft_strdup(array[i++]);
	data->texture->map[++j] = NULL;
	j = -1;
	while (data->texture->map[++j])
	{
		if (width < ft_strlen(data->texture->map[j]))
			width = ft_strlen(data->texture->map[j]);
	}
	data->texture->width = width;
	return (0);
}
