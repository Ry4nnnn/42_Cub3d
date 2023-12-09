/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:21:04 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 15:22:16 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d(char **array);
int		rgb_to_hex(int r, int g, int b);

/**
 * @brief Free a dynamically allocated 2D array of strings.
 *
 * This function frees the memory occupied by a dynamically allocated 2D array
 * of strings. It assumes the array is terminated by a NULL pointer.
 *
 * @param array The 2D array to be freed.
 */
void	free_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * @brief Convert RGB values to hexadecimal color.
 *
 * This function takes RGB values and converts them to a hexadecimal color.
 *
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * @return The hexadecimal color value.
 */
int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}
