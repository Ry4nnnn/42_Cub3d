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

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int degree_to_radian(float degree)
{
    return (degree * PI / 180);
}

int ft_abs(int a)
{
    if (a < 0)
        return (-a);
    return (a);
}