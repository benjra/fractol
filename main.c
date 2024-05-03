#include "fractol.h"

int	main(int ac, char **av)
{
	//u should kow to debug ur code 
	if ((ac == 2 && ft_strcmp(av[1], "mandelbort")) || (ac == 4
			&& ft_strcmp(av[1], "julia")))
	{
		if (ft_strcmp(av[1], "mandelbort"))
			mandel();
		else if (ft_strcmp(av[1], "julia") && is_valid(av[2]) && is_valid(av[3]))
			julia(ft_atod(av[2]), ft_atod(av[3]));
		else
			printf("enter :\n mandelbort OR julia <x> <y> ");
			exit(1);
	}
	else
	{
		printf("enter :\n mandelbort OR julia <x> <y> ");
		exit(1);   
	}
}