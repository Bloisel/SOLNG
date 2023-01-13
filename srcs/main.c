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
    read_map(&dta, argv);
    check_ber(argv, &dta);
    // if (!dta.error)
        // exec;
    ft_exit(&dta);
    return (0);
}