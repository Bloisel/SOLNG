/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:01:03 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/17 17:41:24 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	movement(int keycode, t_data *dta)
{
	if (keycode == 53)
	{
		mlx_destroy_window(dta->mlx, dta->mlx_win);
		ft_exit(dta);
	}
	if (keycode == 13 || keycode == 126)
		move_up(dta);
	if (keycode == 0 || keycode == 123)
		move_left(dta);
	if (keycode == 1 || keycode == 125)
		move_down(dta);
	if (keycode == 2 || keycode == 124)
		move_right(dta);
	exit_possible(dta);
	return (0);
}

int	exitt(int keycode, t_data *dta)
{
	(void)keycode;
	exit(0);
	return (0);
}

void	inti_window2(t_data *dta)
{
	dta->exit2.img = mlx_xpm_file_to_image(dta->mlx, "./img/exit2.xpm",
			&dta->img_height, &dta->img_width);
	dta->exit2.addr = mlx_get_data_addr(dta->exit2.img,
			&dta->exit2.bits_per_pixel,
			&dta->exit2.line_length, &dta->exit2.endian);
	dta->player.img = mlx_xpm_file_to_image(dta->mlx, "./img/player.xpm",
			&dta->img_height, &dta->img_width);
	dta->player.addr = mlx_get_data_addr(dta->player.img,
			&dta->player.bits_per_pixel,
			&dta->player.line_length, &dta->player.endian);
	dta->coins.img = mlx_xpm_file_to_image(dta->mlx, "./img/coins.xpm",
			&dta->img_height, &dta->img_width);
	dta->coins.addr = mlx_get_data_addr(dta->coins.img,
			&dta->coins.bits_per_pixel,
			&dta->coins.line_length, &dta->coins.endian);
	print_image(dta);
	mlx_hook(dta->mlx_win, 2, (1L << 0), movement, dta);
	mlx_hook(dta->mlx_win, 17, (1L << 17), exitt, dta);
	mlx_loop(dta->mlx);
}

void	init_window(t_data *dta)
{
	t_data	img;

	dta->mlx = mlx_init();
	dta->mlx_win = mlx_new_window(dta->mlx, dta->longeur * 32,
			dta->largeur * 32, "SO_Long_bloisel");
	dta->floor.img = mlx_xpm_file_to_image(dta->mlx, "./img/floor.xpm",
			&dta->img_height, &dta->img_width);
	dta->floor.addr = mlx_get_data_addr(dta->floor.img,
			&dta->floor.bits_per_pixel, &dta->floor.line_length,
			&dta->floor.endian);
	dta->wall.img = mlx_xpm_file_to_image(dta->mlx, "./img/wall.xpm",
			&dta->img_height, &dta->img_width);
	dta->wall.addr = mlx_get_data_addr(dta->wall.img, &dta->wall.bits_per_pixel,
			&dta->wall.line_length, &dta->wall.endian);
	dta->exit1.img = mlx_xpm_file_to_image(dta->mlx, "./img/exit1.xpm",
			&dta->img_height, &dta->img_width);
	dta->exit1.addr = mlx_get_data_addr(dta->exit1.img,
			&dta->exit1.bits_per_pixel,
			&dta->exit1.line_length, &dta->exit1.endian);
	inti_window2(dta);
}
