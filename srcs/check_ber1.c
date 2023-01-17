/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:25:37 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/17 17:18:03 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_ber1(char **argv, t_data *dta)
{
	int	i;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	i = ft_strlen(argv[1]);
	if ((argv[1][i - 4] != '.' && argv[1][i - 3] != 'b' &&
			argv[1][i - 2] != 'e' && argv[1][i - 1] != 'r'))
		printf_error(dta, "Error : ce fichier n'est pas un point ber\n");
}

void	check_map(t_data *dta)
{
	int	i;
	int	j;	

	i = 0;
	j = 0;
	while (dta->map[i])
	{
		j = 0;
		while (dta->map[i][j])
		{
			if (dta->map[i][j] == '1' || dta->map[i][j] == '0'
				|| dta->map[i][j] == 'P' || dta->map[i][j] == 'C'
				|| dta->map[i][j] == 'E')
					j++;
			else
				printf_error(dta, "Error : Mauvais arguments dans la map");
		}
		i++;
	}
}

void	check_map_number(t_data *dta, int *e, int *p, int *c)
{
	if (*e > 1)
		printf_error(dta, "Error : too many exit\n");
	if (*p > 1)
		printf_error(dta, "Error : too many players\n");
	if (*c <= 0)
		printf_error(dta, "Error : missing coin\n");
	if (*p <= 0)
		printf_error(dta, "Error : missing player\n");
	if (*e <= 0)
		printf_error(dta, "Error : missing exit\n");
	dta->coinalgo = *c;
}

void	check_map2(t_data *dta)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = -1;
	c = 0;
	e = 0;
	p = 0;
	while (dta->map[++i])
	{
		j = 0;
		while (dta->map[i][j])
		{
			if (dta->map[i][j] == 'C')
				c++;
			if (dta->map[i][j] == 'E')
				e++;
			if (dta->map[i][j] == 'P')
				p++;
			j++;
		}
	}
	check_map_number(dta, &e, &p, &c);
}
