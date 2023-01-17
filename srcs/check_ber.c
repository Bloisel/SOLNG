/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:00:40 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/17 17:17:13 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_rectangle(t_data *dta)
{
	int	i;
	int	j;
	int	l;
	int	la;

	i = 0;
	la = 0;
	l = 0;
	l = ft_strlen(dta->map[++i]);
	dta->longeur = l;
	i = 0;
	while (dta->map[i])
	{
		j = 0;
		while (dta->map[i][j])
		{
		j++;
		}
		i++;
	}
	la = i;
	dta->largeur = la;
	if (l <= la)
		printf_error(dta, "Error : la map n'est pas un rectangle");
}

void	check_map_walls2(t_data *dta, int *y, int *i)
{	
	while (dta->map[++(*i)])
	{
		if (dta->map[*i][0] != '1')
		{
			ft_printf("First char colonne pos [%d][0]\n", i);
			printf_error(dta, "Error : la map n'est pas entouree de wall\n");
		}
		if (dta->map[*i][(*y) - 1] != '1')
		{
			ft_printf("Last char colonne pos :[%d][%d]\n", i, (y - 1));
			printf_error(dta, "Error : la map n'est pas entouree de wall\n");
		}
	}
}

void	check_map_walls1(t_data *dta, int *x, int *j)
{
	int	i;
	int	y;

	i = 0;
	while (dta->map[i][*j] != '\0')
	{
		*j = 0;
		while (dta->map[i][*j])
		{
			if (dta->map[0][*j] != '1')
			{
				ft_printf("First colonne de map pos :[0][%d]\n", j);
				printf_error(dta, "Error : la map n'est pas entouree de wall\n");
			}
			if (dta->map[(*x) - 1][*j] != '1')
			{
				ft_printf("Last colonne de map pos :[%d][%d]\n", (x - 1), j);
				printf_error(dta, "Error : la map n'est pas entouree de wall\n");
			}
			j++;
		}
	}
	y = *j;
	i = 0;
	check_map_walls2(dta, &y, &i);
}

void	check_map_walls(t_data *dta)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	while (dta->map[i])
	{
		x = 0;
		while (dta->map[i][j])
		{
		j++;
		}
		i++;
	}
	x = i;
	check_map_walls1(dta, &x, &j);
}
