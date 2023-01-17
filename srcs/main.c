#include "../include/so_long.h"

void    pose_player(t_data *dta)
{
    int i;
    int j;

    i = 0;
    while (dta->map[i])
    {
        j = 0;
        while (dta->map[i][j])
        {
            if (dta->map[i][j] == 'P')
            {    
            dta->y = i;              
            dta->x = j;
            }
            j++;
        }
        i++;
    }
}

void    pose_exit(t_data *dta)
{
    int i;
    int j;

    i = 0;
    while (dta->map[i])
    {
        j = 0;
        while (dta->map[i][j])
        {
            if (dta->map[i][j] == 'E')
            {    
            dta->a = i;              
            dta->b = j;
            }
            j++;
        }
        i++;
    }
}

void    init_data(t_data *dta)
{
    dta->error = 0;
    dta->mouvement = 0;
    dta->coinpick = 0;
    dta->img_height = 32;
    dta->img_width = 32;
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
    pose_player(&dta);
    pose_exit(&dta);
    check_map(&dta);
    check_map2(&dta);
    check_map_rectangle(&dta);
    check_map_walls(&dta);
    check_path(&dta);
    init_window(&dta);
    ft_exit(&dta);
    return (0);
}