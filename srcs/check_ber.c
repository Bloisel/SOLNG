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
		printf_error(dta,"Error : ce fichier n'est pas un point ber\n");
}

void check_map(t_data *dta)
{
    int i = 0;
    int j = 0;
    
	while (dta->map[i])
    {
        j = 0;
        while (dta->map[i][j])
        {
            if (dta->map[i][j] == '1' || dta->map[i][j] == '0' || dta->map[i][j] == 'P'
                || dta->map[i][j] == 'C' || dta->map[i][j] == 'E')
                	j++;
            else
                printf_error(dta,"Error : Mauvais arguments dans la map");
        }
        i++;
    }
}

void check_map_number(t_data *dta, int *e, int *p, int *c)
{
	if (*e > 1)
		printf_error(dta,"Error : too many exit\n");
	if (*p > 1)
		printf_error(dta,"Error : too many players\n");
	if (*c <= 0)
		printf_error(dta,"Error : missing coin\n");
	if (*p <= 0)
		printf_error(dta,"Error : missing player\n");
	if (*e <= 0)
		printf_error(dta,"Error : missing exit\n");
	dta->coinalgo = *c;
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
			j++;
		}
	}
	check_map_number(dta, &e, &p ,&c);
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
		printf_error(dta,"Error : la map n'est pas un rectangle");
}
void check_map_walls(t_data *dta)
{
	int i;
	int j;
	int x;
	int y;

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
			ft_printf("Error : dans la premiere colonne de la map a la position [0][%d]\n",j);
			printf_error(dta, "Error : la map n'est pas entouree de wall\n");
		}
		if (dta->map[x - 1][j] != '1')
		{
			ft_printf("Error : dans la derniere colonne de la map a la position [%d][%d]\n",(x - 1),j);
			printf_error(dta, "Error : la map n'est pas entouree de wall\n");
		}
		j++;
		}
	}
	y = j;
	i = 0;
	while (dta->map[++i])
	{
		if (dta->map[i][0] != '1')
		{
			ft_printf("Error : au premier caractere de la colonne [%d][0]\n",i);
			printf_error(dta,"Error : la map n'est pas entouree de wall\n");
		}
		if (dta->map[i][y - 1] != '1')
		{
			ft_printf("Error : au derniere caractere de la colonne [%d][%d]\n",i,(y - 1));
			printf_error(dta,"Error : la map n'est pas entouree de wall\n");
		}
	}
}

void check_path2(t_data *dta, int a,int b, int *modif)
{
	if	(dta->map2[a + 1][b] == 'C' || dta->map2[a + 1][b] == '0')
	{
			dta->map2[a + 1][b] = 'B';
			*modif += 1;
	}
	if	(dta->map2[a - 1][b] == 'C' || dta->map2[a - 1][b] == '0')
	{
			dta->map2[a - 1][b] = 'B';
			*modif += 1;
	}
	if	(dta->map2[a][b + 1] == 'C' || dta->map2[a][b + 1] == '0')
	{
			dta->map2[a][b + 1] = 'B';
			*modif += 1;
	}
	if	(dta->map2[a][b - 1] == 'C' || dta->map2[a][b - 1] == '0')
	{
			dta->map2[a][b - 1] = 'B';
			*modif += 1;
	}
}

void check_valid_path(t_data *dta)
{
	int i;
	int j;

	i = 0;
	while (dta->map2[i])
	{
		j = 0;
		while(dta->map2[i][j]) 
		{
			if ((dta->map2[i][j] == 'E' && (dta->map2[i + 1][j] != 'B' && dta->map2[i - 1][j] != 'B')
				&& (dta->map2[i][j + 1] != 'B' && dta->map2[i][j - 1] != 'B')))
					printf_error(dta,"Error : chemin impossible pour exit\n");
			if (dta->map2[i][j] == 'C') 
					printf_error(dta,"Error : chemin impossible pour coins\n");
			j++;
		}
		i++;
	}
}

void check_path(t_data *dta)
{
	int i;
	int j;
	int d;

	d = 1;
	while (d != 0)
	{
		d = 0;
		i = 0;
		while (dta->map2[i])
		{
			j = 0;
			while(dta->map2[i][j]) 
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
