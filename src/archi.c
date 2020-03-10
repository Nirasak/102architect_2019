/*
** EPITECH PROJECT, 2019
** archi.c
** File description:
** archi
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"

bool init_mtx2(ope_t *ope, int i)
{
    for (int j = 0; j < 3; j++) {
        ope->matrix[i][j] = malloc(sizeof(double) * 3);
        if (ope->matrix[i][j] == NULL)
            return (false);
        for (int x = 0; x < 3; x++)
            ope->matrix[i][j][x] = 0;
    }
    ope->matrix[i][0][0] = 1;
    ope->matrix[i][1][1] = 1;
    ope->matrix[i][2][2] = 1;
    return (true);
}

bool init_mtx(int ac, char **av, ope_t *ope)
{
    int size = count_flags(ac, av);

    ope->matrix = malloc(sizeof(double **) * size);
    if (ope->matrix == NULL)
        return (false);
    for (int i = 0; i < size; i++) {
        ope->matrix[i] = malloc(sizeof(double *) * 3);
        if (ope->matrix[i] == NULL)
            return (false);
        if (init_mtx2(ope, i) == false)
            return (false);
    }
    return (true);
}

int archi(int ac, char **av)
{
    ope_t ope;

    if (check_syntax(ac, av, 3) > 0 || check_int(av[1]) != 0
        || check_int(av[2]) != 0)
        return (84);
    ope.flag = malloc(sizeof(char) * (count_flags(ac, av) + 1));
    ope.start = malloc(sizeof(double) * 3);
    if (ope.flag == NULL || ope.start == NULL)
        return (84);
    if (init_mtx(ac, av, &ope) == false)
        return (84);
    init_ope(ac, av, &ope);
    if (calc(count_flags(ac, av), &ope) == false)
        return (84);
    return (0);
}
