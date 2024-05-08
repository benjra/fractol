#include "fractol.h"

int  mouse_zoom(t_mlx vars,int key)
{
	printf("%d", key);
	if(key==4)
	vars.zoom*=1.2;
	else if(key==5)
	vars.zoom/=1.2;
	calcule_mandel();
	return key;
	
}
int	calcule_mand(int i, int it_max, t_complex comp)
{
	double	temp;

	while (comp.z_real * comp.z_real + comp.z_imag * comp.z_imag < 4 && i < it_max)
	{
		temp = comp.z_real * comp.z_real - comp.z_imag * comp.z_imag
			+ comp.c_real;
		comp.z_imag = 2 * comp.z_real * comp.z_imag + comp.c_imag;
		comp.z_real = temp;
		i++;
	}
	return (i);
}

void	coloring_mand(int pos, int i, t_image image, int it_max)
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

void	calcule_mandel(int width, int height, int it_max, t_image image)
{
	int		y;
	int		x;
	double zoom = 2.2;
	double	real;
	double	imag;
			t_complex comp;
	int		i;
	int		pos;

	y = 0;
	x = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			real = (x - width / 2.0) * 4.0 / width * zoom;
			imag = (y - height / 2.0) * 4.0 / height * zoom;
			i = 0;
			pos = 0;
			comp.c_real = real;
			comp.c_imag = imag;
			comp.z_real = 0;
			comp.z_imag = 0;
			i = calcule_mand(i, it_max, comp);
			pos = (y * image.line_len) + (x * (image.pixel_bits / 8));
			coloring_mand(pos, i, image, it_max);
			x++;
		}
		y++;
	}
}
int closing(int keycode,t_mlx mlx)
{
	if(keycode==2)
	mlx_destroy_window(mlx.mlx,mlx.mlx_win); //correct this 
	return(0);
}
void	mandel(void)
{
	int		width;
	int		height;
	t_mlx	minilibix;
	int		it_max;
	t_image	image;

	width = 1000;
	height = 1000;
	it_max = 200;
	minilibix.mlx = mlx_init();
	minilibix.mlx_win = mlx_new_window(minilibix.mlx, width, height, "fractol");
	image.img = mlx_new_image(minilibix.mlx, width, height);
	image.buffer = mlx_get_data_addr(image.img, &image.pixel_bits,
			&image.line_len, &image.endian);
	mlx_mouse_hook(minilibix.mlx_win, mouse_zoom,&minilibix);
	calcule_mandel(width, height, it_max, image);
	mlx_put_image_to_window(minilibix.mlx, minilibix.mlx_win, image.img, 0, 0);
	mlx_hook(minilibix.mlx_win,2,1<<0,closing,&minilibix);//
	mlx_loop(minilibix.mlx);
	
}
