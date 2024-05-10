#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void		mandel(void);
void		julia(double cr, double ci);
int			ft_strcmp(char *s1, char *s2);
double    ft_atod(char *str);
int			ft_isdigit(int c);
int			is_valid(char *av);
void print_str(char *str);

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	double zoom;

}			t_mlx;

typedef struct s_complex
{
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
}			t_complex;

typedef struct s_image
{
	char	*buffer;
	void	*img;
	int		pixel_bits;
	int		line_len;
	int		endian;
}			t_image;


enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct mouse
{
	double crs_cx;
	double crs_cy;
	double max;
	double min;
	double max_iteration;

}	t_mouse;


#endif