#ifndef SO_LONG_H
# define SO_LONG_H

#include"../libft/libft.h"
#include"../ft_printf/ft_printf.h"
#include"../minilibx/mlx.h"
#include "stdio.h"
#include "fcntl.h"
#include "stdlib.h"
#include "mlx.h"


typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;
// struct qui vaut une image 
typedef struct s_data
{
    char **map;
    int longeur;
    int largeur;
    int x;
    int y;
    int a;
    int b;
    char **map2;
    int coinpick;
    int coinalgo;
    int mouvement;
    int error;
    
    void *mlx;
    void *mlx_win;
    int img_width;
    int img_height;
    t_img floor;
    t_img wall;
    t_img player;
    t_img coins;
    t_img exit1;
    t_img exit2; // mon image stocker dans la struct dta/img 
} t_data;

void    pose_player(t_data *dta);
void    init_window(t_data *dta);
void    check_path2(t_data *dta, int a,int b, int *modif);
void    check_path(t_data *dta);
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