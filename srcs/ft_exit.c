#include "../include/so_long.h"

void	free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i] != NULL)
	{
		if (tab[i] != NULL)
			free(tab[i]);
	}
	if (tab != NULL)
		free(tab);
}

void	ft_exit(t_data *dta)
{
	//free_tab(dta->map);
	system("leaks so_long");
	if (dta->error > 0)
		exit(1);
	exit(0);
}

void	printf_error(t_data *dta, char *str)
{
	ft_printf("%s\n\n\n", str);
	dta->error = 1;
	ft_exit(dta);
}