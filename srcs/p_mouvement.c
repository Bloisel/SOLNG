/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_mouvement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:39:13 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/17 17:42:27 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_right(t_data *dta)
{
	if (dta->map[dta->y][dta->x + 1] == 'C')
	{
		dta->coinpick += 1;
		dta->map[dta->y][dta->x + 1] = '0';
	}
	if (dta->map[dta->y][dta->x + 1] != '1')
	{
		dta->mouvement += 1;
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
			(dta->x + 1) * 32, (dta->y) * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img,
			(dta->x + 1) * 32, (dta->y) * 32);
		if (dta->map[dta->y][dta->x] == 'E')
			mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img,
				(dta->x) * 32, (dta->y) * 32);
		else
			mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
				(dta->x) * 32, (dta->y) * 32);
		dta->x += 1;
		ft_printf("Nombre de mouvement : %d\n", dta->mouvement);
	}
}

void	move_left(t_data *dta)
{
	if (dta->map[dta->y][dta->x - 1] == 'C')
	{
		dta->coinpick += 1;
		dta->map[dta->y][dta->x - 1] = '0';
	}
	if (dta->map[dta->y][dta->x - 1] != '1')
	{
		dta->mouvement += 1;
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
			(dta->x - 1) * 32, (dta->y) * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img,
			(dta->x - 1) * 32, (dta->y) * 32);
		if (dta->map[dta->y][dta->x] == 'E')
			mlx_put_image_to_window(dta->mlx, dta->mlx_win,
				dta->exit1.img, (dta->x) * 32, (dta->y) * 32);
		else
			mlx_put_image_to_window(dta->mlx, dta->mlx_win,
				dta->floor.img, (dta->x) * 32, (dta->y) * 32);
	dta->x -= 1;
		ft_printf("Nombre de mouvement : %d\n", dta->mouvement);
	}
}

void	move_up(t_data *dta)
{
	if (dta->map[dta->y - 1][dta->x] == 'C')
	{
		dta->coinpick += 1;
		dta->map[dta->y - 1][dta->x] = '0';
	}
	if (dta->map[dta->y - 1][dta->x] != '1')
	{
		dta->mouvement += 1;
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
			(dta->x) * 32, (dta->y - 1) * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img,
			(dta->x) * 32, (dta->y - 1) * 32);
		if (dta->map[dta->y][dta->x] == 'E')
			mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img,
				(dta->x) * 32, (dta->y) * 32);
		else
			mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
				(dta->x) * 32, (dta->y) * 32);
	dta->y -= 1;
		ft_printf("Nombre de mouvement : %d\n", dta->mouvement);
	}
}

void	move_down(t_data *dta)
{
	if (dta->map[dta->y + 1][dta->x] == 'C')
	{
		dta->coinpick += 1;
		dta->map[dta->y + 1][dta->x] = '0';
	}
	if (dta->map[dta->y + 1][dta->x] != '1')
	{
		dta->mouvement += 1;
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
			(dta->x) * 32, (dta->y + 1) * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img,
			(dta->x) * 32, (dta->y + 1) * 32);
		if (dta->map[dta->y][dta->x] == 'E')
			mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img,
				(dta->x) * 32, (dta->y) * 32);
		else
			mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
				(dta->x) * 32, (dta->y) * 32);
		dta->y += 1;
		ft_printf("Nombre de mouvement : %d\n", dta->mouvement);
	}
}

void	exit_possible(t_data *dta)
{
	if (dta->coinpick < dta->coinalgo
		&& dta->map[dta->y][dta->x] == dta->map[dta->a][dta->b])
	{
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
			(dta->b) * 32, (dta->a) * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit1.img,
			(dta->b) * 32, (dta->a) * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->player.img,
			(dta->x) * 32, (dta->y) * 32);
	}
	if (dta->coinpick == dta->coinalgo)
	{
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->floor.img,
			(dta->b) * 32, (dta->a) * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win, dta->exit2.img,
			(dta->b) * 32, (dta->a) * 32);
		if (dta->map[dta->y][dta->x] == dta->map[dta->a][dta->b])
		{
			mlx_destroy_window(dta->mlx, dta->mlx_win);
			ft_exit(dta);
		}
	}
}
