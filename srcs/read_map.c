/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:01:23 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/17 17:45:42 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map2(t_data *dta, int read_one, char *str, int fd)
{
	int	i;

	i = 0;
	str = ft_calloc(10000, sizeof(char));
	read_one = read (fd, str, 10000);
	if (read_one == -1)
	{
		free(str);
		printf_error(dta, "Error : le fichier n'a pas pu etre lu correctement");
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			printf_error(dta, "Error : trop de newlines map incorrect");
		}
		i++;
	}
	dta->map = ft_split(str, '\n');
	dta->map2 = ft_split(str, '\n');
	free(str);
}

void	read_map(t_data *dta, char **argv)
{
	char		*str;
	int			read_one;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf_error(dta, "Error : le fichier n'a pas pu etre ouvert");
	read_map2(dta, read_one, str, fd);
}
