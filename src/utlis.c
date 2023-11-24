#include "cub3d.h"

void    free_2d(char **array)
{
    int i;

    i = 0;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void    ft_error(t_cub3d *data, char *msg)
{
    int i;

    i = 0;
    if (data->map)
    {
        while (data->map[i])
        {
            free (data->map[i]);
            i++;
        }
        free (data->map);
    }
    printf ("Error: %s.\n", msg);
    exit (1);
}