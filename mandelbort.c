#include "fractol.h"
#include <mlx.h>

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
	char	*p=NULL;

	// printf("=====> here ");
	p = (image.buffer + pos);
	// printf("===> %p",p);
	// exit (1);
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

void	calcule_mandel(int width, int height, int it_max, t_mlx	*minilibix)
{
	int		y;
	int		x;
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
			real = (x - width / 2.0) * 4.0 / width ;
			imag = (y - height / 2.0) * 4.0 / height ;
			i = 0;
			pos = 0;
			comp.c_real = real;
			comp.c_imag = imag;
			comp.z_real = 0;
			comp.z_imag = 0;
			i = calcule_mand(i, it_max, comp);
			pos = (y * minilibix->image->line_len) + (x * (minilibix->image->pixel_bits / 8));
			coloring_mand(pos, i,*(minilibix->image), it_max);
			x++;
		}
		y++;
	}
}


void	mandel(void)
{
	int		width;
	int		height;
	t_mlx	minilibix;
	int		it_max;
	t_image	image;
	t_mlx	*m=&minilibix;

	width = 1000;
	height = 1000;
	it_max = 200;
	minilibix.mlx = mlx_init();
	minilibix.mlx_win = mlx_new_window(minilibix.mlx, width, height, "fractol");

	minilibix.image = (t_image *)malloc(sizeof(t_image)); 
	if (minilibix.image == NULL)
	{
		// Handle allocation failure
		return;
	}
	image.img = mlx_new_image(minilibix.mlx, width, height);
	image.buffer = mlx_get_data_addr(image.img, &image.pixel_bits,
			&image.line_len, &image.endian); 
	calcule_mandel(width, height, it_max, &minilibix);
	mlx_put_image_to_window(minilibix.mlx, minilibix.mlx_win, image.img, 0, 0);

	mlx_key_hook(minilibix.mlx_win, handle_keys, m);
	
	mlx_mouse_hook(minilibix.mlx_win, mouse_hook, m);

	mlx_loop(minilibix.mlx);
	
}
//mlx_hook(minilibix.mlx_win,17,0,closing,m);
// if(minilibix.mlx_win==NULL)
	// {
	// 	free(minilibix.mlx_win);
    //     exit(1);
	// }