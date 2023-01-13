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