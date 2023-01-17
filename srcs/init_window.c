#include "../include/so_long.h"

void    print_image(t_data *dta)
{
    int i;
    int j;

    i = 0;
    while (dta->map[i])
    {
        j = 0;
        while (dta->map[i][j])
        {
            if (dta->map[i][j] == '0')
                mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, j * 32, i * 32);
            if (dta->map[i][j] == '1')
                mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->wall.img, j * 32, i * 32);
            if (dta->map[i][j] == 'E')
                mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img, j * 32, i * 32);
            if (dta->map[i][j] == 'P')
            {
                mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, j * 32, i * 32);
                mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img, j * 32, i * 32);
            }
            if (dta->map[i][j] == 'C')
            {
                mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, j * 32, i * 32);
                mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->coins.img, j * 32, i * 32);
            }
        j++;
        }
        i++;    
    }
}

void    move_right(t_data *dta)
{
        if (dta->map[dta->y][dta->x + 1] == 'C') 
        {
            dta->coinpick += 1;
            dta->map[dta->y][dta->x + 1] = '0';
        }
        if (dta->map[dta->y][dta->x + 1] != '1')
        {
            dta->mouvement += 1;
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->x + 1) * 32, (dta->y) * 32);
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img, (dta->x + 1) * 32, (dta->y) * 32);
            if (dta->map[dta->y][dta->x] == 'E')
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img, (dta->x) * 32, (dta->y) * 32); 
            else 
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->x) * 32, (dta->y) * 32);            
            dta->x += 1;
            ft_printf("Nombre de mouvement : %d\n", dta->mouvement);
        }
}

void    move_left(t_data *dta)
{
        if (dta->map[dta->y][dta->x - 1] == 'C')
        {
            dta->coinpick += 1;
            dta->map[dta->y][dta->x - 1] = '0';
        }
        if (dta->map[dta->y][dta->x - 1] != '1')
        {
            dta->mouvement += 1;
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->x - 1) * 32, (dta->y) * 32);
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img, (dta->x - 1) * 32, (dta->y) * 32);
            if (dta->map[dta->y][dta->x] == 'E')
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img, (dta->x) * 32, (dta->y) * 32); 
            else 
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->x) * 32, (dta->y) * 32);
            dta->x -= 1;
            ft_printf("Nombre de mouvement : %d\n", dta->mouvement);
        }

}

void    move_up(t_data *dta)
{
        if (dta->map[dta->y - 1][dta->x] == 'C')
        {
            dta->coinpick += 1;
            dta->map[dta->y - 1][dta->x] = '0';
        }
        if (dta->map[dta->y - 1][dta->x] != '1')
        {
            dta->mouvement += 1;
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->x) * 32, (dta->y - 1) * 32);
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img, (dta->x) * 32, (dta->y - 1) * 32);
            if (dta->map[dta->y][dta->x] == 'E')
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img, (dta->x) * 32, (dta->y) * 32); 
            else 
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->x) * 32, (dta->y) * 32);
            dta->y -= 1;
            ft_printf("Nombre de mouvement : %d\n", dta->mouvement);
        }
}

void    move_down(t_data *dta)
{
        if (dta->map[dta->y + 1][dta->x] == 'C')
        {
            dta->coinpick += 1;
            dta->map[dta->y + 1][dta->x] = '0';
        }
        if (dta->map[dta->y + 1][dta->x] != '1')
        {
            dta->mouvement += 1;
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->x) * 32, (dta->y + 1) * 32);
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img, (dta->x) * 32, (dta->y + 1) * 32);
            if (dta->map[dta->y][dta->x] == 'E')
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img, (dta->x) * 32, (dta->y) * 32); 
            else 
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->x) * 32, (dta->y) * 32);
            dta->y += 1;
            ft_printf("Nombre de mouvement : %d\n", dta->mouvement);
        }
}

void exit_possible(t_data *dta)
{
        if (dta->coinpick < dta->coinalgo && dta->map[dta->y][dta->x] == dta->map[dta->a][dta->b])
        {
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->b) * 32, (dta->a) * 32);
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img, (dta->b) * 32, (dta->a) * 32);
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img, (dta->x) * 32, (dta->y) * 32);
        }
        if (dta->coinpick == dta->coinalgo) 
        {
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img, (dta->b) * 32, (dta->a) * 32);
            mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit2.img, (dta->b) * 32, (dta->a) * 32);
        if (dta->map[dta->y][dta->x] == dta->map[dta->a][dta->b])
        {
            mlx_destroy_window(dta->mlx, dta->mlx_win);
            ft_exit(dta);
        }
        }
}



int movement (int keycode, t_data *dta)
{
    if (keycode == 53)
    {
        mlx_destroy_window(dta->mlx, dta->mlx_win);
        ft_exit(dta);
    }
    if (keycode == 13 || keycode == 126) 
    {   
        move_up(dta);     
    } 
    if (keycode == 0 || keycode ==  123 ) 
    {
        move_left(dta); 
    }
    if (keycode == 1 || keycode == 125) 
    {
        move_down(dta);  
    }
     if (keycode == 2 || keycode == 124)
    {
        move_right(dta);
    }
    exit_possible(dta);
    return (0);
}
int exitt(int keycode, t_data *dta)
{
    (void)keycode;
    exit(0);
    return (0);
}


void    init_window(t_data *dta)
{
    t_data	img;

    dta->mlx = mlx_init();
    dta->mlx_win = mlx_new_window(dta->mlx, dta->longeur * 32 , dta->largeur * 32, "SO_Long_bloisel");
    dta->floor.img = mlx_xpm_file_to_image(dta->mlx, "./img/floor.xpm", &dta->img_height, &dta->img_width);
    dta->floor.addr = mlx_get_data_addr(dta->floor.img, &dta->floor.bits_per_pixel, &dta->floor.line_length, &dta->floor.endian);
    dta->wall.img = mlx_xpm_file_to_image(dta->mlx, "./img/wall.xpm", &dta->img_height, &dta->img_width);
    dta->wall.addr = mlx_get_data_addr(dta->wall.img, &dta->wall.bits_per_pixel, &dta->wall.line_length, &dta->wall.endian);
    dta->exit1.img = mlx_xpm_file_to_image(dta->mlx, "./img/exit1.xpm", &dta->img_height, &dta->img_width);
    dta->exit1.addr = mlx_get_data_addr(dta->exit1.img, &dta->exit1.bits_per_pixel, &dta->exit1.line_length, &dta->exit1.endian);
    dta->exit2.img = mlx_xpm_file_to_image(dta->mlx, "./img/exit2.xpm", &dta->img_height, &dta->img_width);
    dta->exit2.addr = mlx_get_data_addr(dta->exit2.img, &dta->exit2.bits_per_pixel, &dta->exit2.line_length, &dta->exit2.endian); 
    dta->player.img = mlx_xpm_file_to_image(dta->mlx, "./img/player.xpm", &dta->img_height, &dta->img_width);
    dta->player.addr = mlx_get_data_addr(dta->player.img, &dta->player.bits_per_pixel, &dta->player.line_length, &dta->player.endian);
    dta->coins.img = mlx_xpm_file_to_image(dta->mlx, "./img/coins.xpm", &dta->img_height, &dta->img_width);
    dta->coins.addr = mlx_get_data_addr(dta->coins.img, &dta->coins.bits_per_pixel, &dta->coins.line_length, &dta->coins.endian);
    print_image(dta);
    mlx_hook(dta->mlx_win, 2, (1L<<0), movement, dta);
    mlx_hook(dta->mlx_win, 17, (1L<<17), exitt, dta);
    mlx_loop(dta->mlx);
}