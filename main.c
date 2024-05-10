#include "fractol.h"
void ft_strlower(char *av)
{
	int i=0;
	while (av[i])
	{
		if(av[i]<='Z' && av[i]>='A')
			av[i]+=32;
		i++;
	}
	
}
int	main(int ac, char **av)
{
	ft_strlower(av[1]);
	if ((ac == 2 && ft_strcmp(av[1], "mandelbort")) || (ac == 4
			&& ft_strcmp(av[1], "julia")))
	{
		if (ft_strcmp(av[1], "mandelbort"))
			mandel();
		else if (ft_strcmp(av[1], "julia") && is_valid(av[2]) && is_valid(av[3]))
			julia(ft_atod(av[2]), ft_atod(av[3]));
		else
			print_str("Please Enter :\nmandelbort OR julia <x> <y> ");
	}
	else
	{
		print_str("Please Enter :\nmandelbort OR julia <x> <y> ");
		exit(1);
   
	}
}
                           
