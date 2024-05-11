#include "fractol.h"


int closing(int keyy,t_mlx mlx)
{
	(void)keyy;
	mlx_destroy_image();
	mlx_destroy();
	mlx_destroy_window(mlx.mlx,mlx.mlx_win); 
	free(mlx);
	return(0);
}
 
int	handle_keys(int keysym,t_mlx *data)
{
    if (keysym == 2)
    mlx_destroy_window(data.mlx, data.mlx_win);
	printf("%d\n",keysym);
    return (0);
}

int  mouse_hook(int key,t_mlx *vars)
{
	if(key==4 || key==5)
	{
		if(key==4)
		vars.zoom*=1.15;
		else if(key==5)
		vars.zoom*=0.85;
		mlx_destroy_image(vars->image.img);
		initialiser()
	calcule_mandel(900,800,vars->mouse.max_iteration,vars->image.img);
	}
	return key;
	
}