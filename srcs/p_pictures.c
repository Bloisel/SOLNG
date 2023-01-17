/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_pictures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:36:01 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/17 17:40:27 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_image2(t_data *dta, int i, int j)
{
	if (dta->map[i][j] == 'P')
	{
		mlx_put_image_to_window(dta->mlx, dta->mlx_win,
			dta->floor.img, j * 32, i * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win,
			dta->player.img, j * 32, i * 32);
	}
	if (dta->map[i][j] == 'C')
	{
		mlx_put_image_to_window(dta->mlx, dta->mlx_win,
			dta->floor.img, j * 32, i * 32);
		mlx_put_image_to_window(dta->mlx, dta->mlx_win,
			dta->coins.img, j * 32, i * 32);
	}
}

void	print_image(t_data *dta)
{
	int	i;
	int	j;

	i = 0;
	while (dta->map[i])
	{
		j = 0;
		while (dta->map[i][j])
		{
			if (dta->map[i][j] == '0')
				mlx_put_image_to_window(dta->mlx, dta->mlx_win,
					dta->floor.img, j * 32, i * 32);
			if (dta->map[i][j] == '1')
				mlx_put_image_to_window(dta->mlx, dta->mlx_win,
					dta->wall.img, j * 32, i * 32);
			if (dta->map[i][j] == 'E')
				mlx_put_image_to_window(dta->mlx, dta->mlx_win,
					dta->exit1.img, j * 32, i * 32);
			print_image2(dta, i, j);
			j++;
		}
		i++;
	}
}
