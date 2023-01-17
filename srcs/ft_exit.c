#include "../include/so_long.h"

void	ft_exit(t_data *dta)
{
	// system("leaks so_long");
	if (dta->error > 0)
		exit(1);
	exit(0);
}

void	printf_error(t_data *dta, char *str)
{
	ft_printf("%s\n", str);
	dta->error = 1;
	ft_exit(dta);
}