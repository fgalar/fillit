#include <stdio.h>
#include "../libft/libft.h"

int    check_form(char **buffer)
{
    int         i;
    int         error;

    i = 0;
    error = 0;
    while (*buffer[i] && i < 19)
    {
        while (*buffer[i] && (((i + 1)% 5) != 0 || i == 0))
        {
            if (*buffer[i] == '.' || *buffer[i] == '#')
                i++;
            else
                error = 1;
        }
            if ((i < 19 && *buffer[i] == '\n') && error == 0)
                i++;
            else
                error = 1;
    }
    if (!(*buffer[i] == '\n') || !(*buffer[i] == '\0'))
        error = 1;
    return (error);
}

int     main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("error = %d\n", check_form(&av[1]));
    }
    return (0);
}