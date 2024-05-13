#include "fractol.h"


// int closing(int keyy,t_mlx mlx)
// {
// 	(void)keyy;
// 	mlx_destroy_image();
// 	mlx_destroy();
// 	mlx_destroy_window(mlx.mlx,mlx.mlx_win);
// 	free(mlx);
// 	return(0);
// }
 
int	handle_keys(int keysym,t_mlx *data)
{
    if (keysym == 2)
    mlx_destroy_window(data->mlx, data->mlx_win);
	printf("%d\n",keysym);
    return (0);
}
void initialiser(t_mouse *vars) {
    vars->crs_cx = 1;
    vars->crs_cy = 1;
    vars->max_iteration = 200;
    vars->max_x = 2;
    vars->max_y = 2;
    vars->min_x = -2;
    vars->min_y = -2;
}
#include <string.h>
int mouse_hook(int key,int x, int y,  t_mlx *vars) {
    (void)x;
    (void)y;
    if (key == 4 || key == 5) {
        if (key == 4)
            vars->zoom *= 1.15;
        else if (key == 5)
            vars->zoom *= 0.85;
        // initialiser(&(vars->mouse));
        mlx_clear_window ( vars->mlx, vars->mlx_win);
        // memset((void *)vars->image,0,sizeof(vars->image));		
        calcule_mandel(vars->width, vars->height, vars->mouse.max_iteration, vars);
    }
    return key;	
}

// vars->image.img = mlx_new_image(vars->mlx, vars->width,vars->height);
		// vars->image.buffer= mlx_get_data_addr(vars->image.img, &vars->image.pixel_bits,
		// 	&vars->image.line_len, &vars->image.endian);