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