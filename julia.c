#include "fractol.h"

int	calcule(int i, int it_max, t_complex comp)
{
	double	temp;

	while (comp.z_real * comp.z_real + comp.z_imag * comp.z_imag < 4
		&& i < it_max)
	{
		temp = comp.z_real * comp.z_real - comp.z_imag * comp.z_imag
			+ comp.c_real;
		comp.z_imag = 2 * comp.z_real * comp.z_imag + comp.c_imag;
		comp.z_real = temp;
		i++;
	}
	return (i);
}

void	coloring_julia(int pos, int i, t_image image, int it_max)
{
	char	*p;

	p = (image.buffer + pos);
	if (i == it_max)
	{
		*(unsigned int *)p = 0;
	}
	else
	{
		*(unsigned int *)p = (i * (0xFFFFFF - 0x000000) / (it_max - 0)
				+ 0x000000);
	}
}
void	calcule_julia(int width, int height, t_image image, t_complex comp,
		int it_max)
{
	int		y;
	int		x;
	double	real;
	double	imag;
	int		i;
	int		pos;

	y = 0;
	x = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			real = (x - width / 2.0) * 4.0 / width;
			imag = (y - height / 2.0) * 4.0 / height;
			i = 0;
			pos = 0;
			comp.z_real = real;
			comp.z_imag = imag;
			i = calcule(i, it_max, comp);
			pos = (y * image.line_len) + (x * (image.pixel_bits / 8));
			coloring_julia(pos, i, image, it_max);
			x++;
		}
		y++;
	}
}
void	julia(double cr, double ci)
{
	int			width;
	int			height;
	t_mlx		minilibix;
	int			it_max;
	t_image		image;
	t_complex	comp;
	//char		*buffer;

	width = 800;
	height = 860;
	it_max = 200;
	minilibix.mlx = mlx_init();
	minilibix.mlx_win = mlx_new_window(minilibix.mlx, width, height, "fractol");
	image.img = mlx_new_image(minilibix.mlx, width, height);
	image.buffer = mlx_get_data_addr(image.img, &image.pixel_bits, &image.line_len,
			&image.endian);
	comp.c_real = cr;
	comp.c_imag = ci;
	calcule_julia(width, height, image, comp, it_max);
	mlx_put_image_to_window(minilibix.mlx, minilibix.mlx_win, image.img, 0, 0);
	mlx_loop(minilibix.mlx);
}
