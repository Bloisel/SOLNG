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


void    read_map(t_data *dta,char **argv);
void    check_ber(char **argv, t_data *dta);
void    printf_error(t_data *dta, char *str);
void	ft_exit(t_data *dta);

#endif