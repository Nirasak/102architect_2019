/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check error
*/

#include <string.h>
#include "my.h"

int check_int(char *nb)
{
    for (int i = 0; nb[i] != '\0'; i++)
        if ((nb[i] < '0' || nb[i] > '9') && nb[i] != '-' && nb[i] != '.')
            return (1);
    return (0);
}

int check_syntax(int ac, char **av, int i)
{
    int value = 0;

    if ((strcmp(av[i], "-t") == 0 || strcmp(av[i], "-z") == 0) && ac > i + 2) {
        value += check_int(av[i + 1]);
        value += check_int(av[i + 2]);
        i += 3;
    } else if (
        (strcmp(av[i], "-r") == 0 || strcmp(av[i], "-s") == 0) && ac > i + 1) {
        value += check_int(av[i + 1]);
        i += 2;
    } else {
        i++;
        value++;
    }
    if (i < ac)
        return (value + check_syntax(ac, av, i));
    return (value);
}
