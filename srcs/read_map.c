#include "../include/so_long.h"

void read_map(t_data *dta, char **argv)
{
    int read_one;
    char *str;

    int i;
    int fd;
    fd = open(argv[1],O_RDONLY);
    if (fd == -1)
        printf_error(dta, "Error : le fichier n'a pas pu etre ouvert");
    str = ft_calloc(10000, sizeof(char));
    read_one = read (fd, str, 10000);
    if (read_one == -1)
    {
        free(str);
        printf_error(dta, "Error : le fichier n'a pas pu etre lu correctement");
    }
    while (str[i])
    {
        if (str[i] == '\n' && str[i + 1] == '\n')
        {
            free(str);
            printf_error(dta, "Error : trop de newlines la map n'a pas pu etre lu correctement");
        }
        i++;
    }
    dta->map = ft_split(str,'\n');
    dta->map2 = ft_split(str,'\n');
    free(str);
}