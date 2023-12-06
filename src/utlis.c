#include "cub3d.h"

/**
 * @brief Free a dynamically allocated 2D array of strings.
 *
 * This function frees the memory occupied by a dynamically allocated 2D array
 * of strings. It assumes the array is terminated by a NULL pointer.
 *
 * @param array The 2D array to be freed.
 */
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

// void    ft_error(t_cub3d *data, char *msg)
// {
//     int i;

//     i = 0;
//     if (data->map)
//     {
//         while (data->map[i])
//         {
//             free (data->map[i]);
//             i++;
//         }
//         free (data->map);
//     }
//     printf ("Error: %s.\n", msg);
//     exit (1);
// }

/**
 * @brief Swap the values of two integers.
 *
 * This function swaps the values of two integers using a temporary variable.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * @brief Convert degrees to radians.
 *
 * This function converts an angle from degrees to radians.
 *
 * @param degree The angle in degrees.
 * @return The angle in radians.
 */
int degree_to_radian(float degree)
{
    return (degree * PI / 180);
}

/**
 * @brief Find the absolute value of an integer.
 *
 * This function returns the absolute value of the given integer.
 *
 * @param a The integer.
 * @return The absolute value of the integer.
 */
int ft_abs(int a)
{
    if (a < 0)
        return (-a);
    return (a);
}