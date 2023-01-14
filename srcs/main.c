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
    check_ber(argv, &dta);
    read_map(&dta, argv);
    // check_map(&dta);
    // check_map2(&dta);
    // check_map_rectangle(&dta);
    check_map_walls(&dta);
    // if (!dta.error)
        // exec;
    ft_exit(&dta);
    return (0);
}