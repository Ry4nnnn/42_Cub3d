/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:00:00 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 15:00:01 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_exit(t_cub3d *data);

int	error_exit(t_cub3d *data)
{
	free(data->texture->north);
	free(data->texture->south);
	free(data->texture->east);
	free(data->texture->west);
	free(data->texture->door);
	free(data->texture);
	free(data->player);
	free(data->ray);
	if (data->texture->map != NULL)
		free_2d(data->texture->map);
	free(data);
	exit(1);
}