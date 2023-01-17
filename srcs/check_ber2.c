/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:29:09 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/17 17:18:55 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_path2(t_data *dta, int a, int b, int *modif)
{
	if (dta->map2[a + 1][b] == 'C' || dta->map2[a + 1][b] == '0')
	{
			dta->map2[a + 1][b] = 'B';
			*modif += 1;
	}
	if (dta->map2[a - 1][b] == 'C' || dta->map2[a - 1][b] == '0')
	{
			dta->map2[a - 1][b] = 'B';
			*modif += 1;
	}
	if (dta->map2[a][b + 1] == 'C' || dta->map2[a][b + 1] == '0')
	{
			dta->map2[a][b + 1] = 'B';
			*modif += 1;
	}
	if (dta->map2[a][b - 1] == 'C' || dta->map2[a][b - 1] == '0')
	{
			dta->map2[a][b - 1] = 'B';
			*modif += 1;
	}
}

void	check_valid_path(t_data *dta)
{
	int	i;
	int	j;

	i = 0;
	while (dta->map2[i])
	{
		j = 0;
		while (dta->map2[i][j])
		{
			if ((dta->map2[i][j] == 'E' && (dta->map2[i + 1][j] != 'B'
				&& dta->map2[i - 1][j] != 'B')
					&& (dta->map2[i][j + 1] != 'B'
						&& dta->map2[i][j - 1] != 'B')))
				printf_error(dta, "Error : chemin impossible pour exit\n");
			if (dta->map2[i][j] == 'C')
				printf_error(dta, "Error : chemin impossible pour coins\n");
			j++;
		}
		i++;
	}
}

void	check_path(t_data *dta)
{
	int	i;
	int	j;
	int	d;

	d = 1;
	while (d != 0)
	{
		d = 0;
		i = 0;
		while (dta->map2[i])
		{
			j = 0;
			while (dta->map2[i][j])
			{
				if (dta->map2[i][j] == 'P' || dta->map2[i][j] == 'B')
					check_path2(dta, i, j, &d);
				j++;
			}
		i++;
		}
	}
	check_valid_path(dta);
}
