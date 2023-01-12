#include "../include/so_long.h"

void    init_data(t_data *dta)
{
    dta->error = 0;
}

int main(int argc, char **argv)
{
    t_data dta;

    if (argc != 2)
    {
        ft_printf("%s\n", "Usage : ./so_long [map]");
        return (1);
    }
    init_data(&dta);
    ft_putstr_fd("string\n", 1);
    ft_printf("OUIOUI\n");


    return (0);
}