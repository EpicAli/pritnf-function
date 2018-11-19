/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** add dispstdarg function
*/

#include <stdarg.h>
#include "../include/my.h"
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int rep = 0;

    while (str[rep] != '\0') {
        my_putchar(str[rep]);
        rep = rep + 1;
    }
}

int disp_stdarg(char *s, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, s);
    while (s[i] != '\0')
    {
        if (s[i] == 'c')
        my_putchar(va_arg(ap, int));
        if (s[i] == 'i')
        my_put_nbr(va_arg(ap, int));
        if (s[i] == 's')
        my_putstr(va_arg(ap, char *));
        my_putchar('\n');
        i++;
    }
    va_end(ap);
    return (0);
}

int my_put_nbr(int nb)
{
    long mod;

    if (nb == -2147483648) {
        my_put_nbr(-214748364);
        my_putchar('8');
        return (1);
    }
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + '0');
    } else if (nb < 0) {
        my_putchar(45);
        nb = nb * (-1);
        my_put_nbr(nb);
    } else {
        my_put_nbr(nb/10);
        my_putchar(nb%10 + '0');
    }
}

int main()
{
    int val;
    val = disp_stdarg("csiis", 'X', "hi", 10, -3, "plop");
}