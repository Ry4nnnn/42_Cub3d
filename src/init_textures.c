/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:23 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:08:18 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_textures(t_cub3d *data, char *str);

/**
 * @brief Initialize textures based on a given string.
 *
 * This function initializes texture data structures based on a string
 * representing a line from the configuration file. It handles different
 * types of textures, such as north, south, west, east, and door textures.
 *
 * @param data The main data structure for the application.
 * @param str The string representing a line from the configuration file.
 * @return 1 if an error occurs, 0 otherwise.
 */
int	init_textures(t_cub3d *data, char *str)
{
	char	*path;

	if (ft_strchr(str, '.') == NULL)
		return (1);
	path = ft_strjoin("./images/", ft_strchr(str, '.') + 2);
	if (!ft_strncmp(str, "NO ", 3))
		return (init_north(data, path));
	else if (!ft_strncmp(str, "SO ", 3))
		return (init_south(data, path));
	else if (!ft_strncmp(str, "WE ", 3))
		return (init_west(data, path));
	else if (!ft_strncmp(str, "EA ", 3))
		return (init_east(data, path));
	else if (!ft_strncmp(str, "DO ", 3))
		return (init_door(data, path));
	else
	{
		free (path);
		return (1);
	}
	return (0);
}
