#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s2[i] || s1[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c != '\0')
	{
		if ((c <= '9' && c >= '0' ))
			return (1);
		else
			return (0);
	}
	return (0);
}
int ft_strlen(char *str)
{
	int i=0;
	while(str[i])
		i++;
	return i;
}
int is_valid(char *av)
{
    int i=0;
    int f = 0;
    if (av[i]== '+'||av[i]== '-')
        av++;
  while(av[i] && (ft_isdigit(av[i]) || (av[i] == '.' && av[i+1])))
    {
        if (av[i]== '.')
            f++;
        if(f == 2 )
            return (0);
        i++;
    }

    return (ft_strlen(av) == i && i != 0);
}

double    ft_atod(char *str)
{
    int            i;
    int            sign;
    int     resi;
    double resd; 
    int j=1;

    i = 0;
    sign = 1;
    resi = 0;
    resd=0.0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if(str[i++] == '-')
            sign = -sign;
    }
    while (str[i] <= '9' && str[i] >= '0')
        resi = resi * 10 + str[i++] - '0';
    while ((str[i] <= '9' && str[i] >= '0' )|| str[i]=='.')
    {
        if (str[i] == '.')
            i++;
        while (ft_isdigit((unsigned char)str[i]))
            resd += (str[i++] - '0') / pow(10, j++);
    }
    return (resd+resi * sign);
}
