/*
** EPITECH PROJECT, 2019
** print_descr.c
** File description:
** print descr
*/

#include <stdio.h>

int print_descr(char *file)
{
    printf(
        "USAGE\n"
        "    %s x y transfo1 arg11 [arg12] [transfo2 arg12 "
        "[arg22]] ...\n\n"
        "DESCRIPTION\n"
        "    x   abscissa of the original point\n"
        "    y   ordinate of the original point\n\n"
        "    transfo arg1 [arg2]\n"
        "    -t i j  translation along vector (i, j)\n"
        "    -z m n  scaling by factors m (x-axis) and n (y-axis)\n"
        "    -r d    rotation centered in 0 by a d degree angle\n"
        "    -s d    reflection over the axis passing through 0 with "
        "an inclination\n            angle of d degrees\n", file);
    return (0);
}
