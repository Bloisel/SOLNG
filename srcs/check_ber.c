#include "../include/so_long.h"

void check_ber(char **argv, t_data *dta)
{
	int i;
	int fd;

	fd = open(argv[1],O_RDONLY);

	i = ft_strlen(argv[1]);
	
	if ((argv[1][i - 4] == '.' && argv[1][i - 3] == 'b' && 
			argv[1][i - 2] == 'e' && argv[1][i - 1] == 'r'))
	{
		EXIT_SUCCESS;
	}
	else
	{
		printf_error(dta,"Error : ce fichier n'est pas un point ber\n");
	}
}

void check_map(t_data *dta)
{
    int i = 0;
    int j = 0;
    //printf("%s\n",dta);
    //str = dta->map;
    while (dta->map[i])
    {
        j = 0;
        while (dta->map[i][j])
        {
            if (dta->map[i][j] == '1' || dta->map[i][j] == '0' || dta->map[i][j] == 'P'
                || dta->map[i][j] == 'C' || dta->map[i][j] == 'E')
            {
				//ft_printf("%c\n",dta->map[i][j]);
                j++;
            }
            else
            {
                printf_error(dta,"Error : Mauvais arguments dans la map");
            }        
        }
        i++;
    }
}

void check_map2(t_data *dta)
{
	int i;
	int j;
	int c;
	int e;
	int p;

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
			ft_printf("%c\n",dta->map[i][j]);
			j++;
		}
	}
	check_map_number(dta, &e, &p ,&c);
}

void check_map_number(t_data *dta, int *e, int *p, int *c)
{
	if (*e > 1)
		ft_printf("Error : too many exit\n");
	if (*p > 1)
		ft_printf("Error : too many players\n");
	if (*c <= 0)
		ft_printf("Error : missing coin\n");
	if (*p <= 0)
		ft_printf("Error : missing player\n");
	if (*e <= 0)
		ft_printf("Error : missing exit\n");
}

void check_map_rectangle(t_data *dta)
{
	int i;
	int j;
	int l;
	int la;
	
	i = 0;
	la = 0;
	l = 0;
	l = ft_strlen(dta->map[++i]);
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
	if (l <= la)
		printf_error(dta,"Error : la map n'est pas un rectangle");
}
void check_map_walls(t_data *dta)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	// y = ft_strlen(dta->map[i]);
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
	i = 0;
	j = 0;
	while (dta->map[i][j] != '\0')
	{
		j = 0;
		while (dta->map[i][j])
		{
		if (dta->map[0][j] != '1')
		{
			ft_printf("Erreur : a la premiere ligne de la map [0][%d]\n",j);
			// ft_printf("i = %d\n et j = %d\n",i,j);
			// ft_printf("premier ligne\n");
			// ft_printf("%c\n",dta->map[i][j]);
			// printf_error(dta, "Error : la map n'est pas entouree de wall");
		}
		if (dta->map[x - 1][j] != '1')
		{
			// ft_printf("%d\n",j);
			ft_printf("Erreur : a la derniere ligne de la map [%d][%d]\n",(x - 1),j);
		}
		// 	// ft_printf("i = %d\n et j = %d\n",i,j);
		// 	// ft_printf("premier ligne\n");
		// 	// ft_printf("%c\n",dta->map[i][j]);
		// 	// printf_error(dta, "Error : la map n'est pas entouree de wall");
		// }
		j++;
		}
	}
	y = j;
	i = 0;
	// ft_printf("valeur de mon j : %d\n",j);
	//j = z;
	while (dta->map[++i])
	{
		//j = 0;
		if (dta->map[i][0] != '1')
		{
			ft_printf("Erreur : au premier caracteres de la ligne [%d][0] debut de tab\n",i);
		// 	ft_printf("mon j (char dans la chaine) %d\n",j);
		// 	ft_printf("mon i (nombre de chaine) %d\n",i);
		// 	printf_error(dta,"Error : la map n'est pas entouree de wall");
		// }
		}
		if (dta->map[i][y - 1] != '1')
		{
			ft_printf("Erreur : au derniere caracteres de la ligne [%d][%d]\n",i,(y - 1));
			// ft_printf("mon j (char dans la chaine) %d\n",j);
			// ft_printf("mon i (nombre de chaine) %d\n",i);
			// printf_error(dta,"Error : la map n'est pas entouree de wall");
		}
	}
}

	// if (dta->map[i][j] != '1' && dta->map[x][y] != '1')
		// {
		// 	ft_printf("i = %d\n et j = %d\n",i,j);
		// 	ft_printf("%c\n",dta->map[i][j]);
		// 	ft_printf("dernier chaine de carac");
		// 	printf_error(dta, "Error : la map n'est pas entouree de wall");
		// }		