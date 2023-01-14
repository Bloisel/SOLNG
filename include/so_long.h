#ifndef SO_LONG_H
# define SO_LONG_H

#include"../libft/libft.h"
#include"../ft_printf/ft_printf.h"
#include"../minilibx/mlx.h"
#include "stdio.h"
#include "fcntl.h"
#include "stdlib.h"

typedef struct s_data
{
    char **map;
    int error;
} t_data;

void    check_map_rectangle(t_data *dta);
void    check_map_walls(t_data *dta);
void    check_map2(t_data *dta);
void    check_map(t_data *dta);
void    read_map(t_data *dta,char **argv);
void    check_ber(char **argv, t_data *dta);
void    printf_error(t_data *dta, char *str);
void	ft_exit(t_data *dta);
void    check_map_number(t_data *dta, int *e, int *p, int *c);

#endif