#include <stdio.h>
#include <math.h>
#include <ctype.h>

double    ft_atof(char *str)
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
        while (isdigit((unsigned char)str[i]))
            resd += (str[i++] - '0') / pow(10, j++);
    }
    return (resd+resi * sign);
}

int main() {
double res=ft_atof(".768");
printf("%f",res);
  return 0;
}