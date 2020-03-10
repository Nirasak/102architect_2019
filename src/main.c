/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <string.h>
#include "my.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        return (print_descr(av[0]));
    if (ac >= 5)
        return (archi(ac, av));
    return (84);
}
