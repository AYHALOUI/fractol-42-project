/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:41:33 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/17 19:27:38 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_wrong_fractal_type(void)
{
	ft_putstr("Wrong fractol type\n");
	ft_putstr("Usage: ./fractol [fractal_name]\n");
	ft_putstr("fractal_name: mandelbrot, julia, burningship\n");
	exit (0);
}

int	destroy(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
	exit (0);
}

void	help_key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 18)
		fractol->color_index = 0;
	else if (keycode == 19)
		fractol->color_index = 1;
	else if (keycode == 20)
		fractol->color_index = 2;
	else if (keycode == 21)
		fractol->color_index = 3;
	else if (keycode == 22)
		fractol->color_index = 4;
	else if (keycode == 23)
		fractol->color_index = 5;
}

int	key_hook(int keycode, t_fractol *fractol)
{
	help_key_hook(keycode, fractol);
	if (keycode == 123)
		fractol->x += 0.1;
	else if (keycode == 124)
		fractol->x -= 0.1;
	else if (keycode == 125)
		fractol->y -= 0.1;
	else if (keycode == 126)
		fractol->y += 0.1;
	else if (keycode == 53)
		destroy(fractol);
	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	choose_fractal(fractol, fractol->c_real, fractol->c_img);
	mlx_put_image_to_window(fractol->mlx_ptr,
		fractol->win_ptr, fractol->img_ptr, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)(x);
	(void)(y);
	if (button == 4)
		fractol->zoom /= 1.2;
	else if (button == 5)
		fractol->zoom *= 1.2;
	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	choose_fractal(fractol, fractol->c_real, fractol->c_img);
	mlx_put_image_to_window(fractol->mlx_ptr,
		fractol->win_ptr, fractol->img_ptr, 0, 0);
	return (0);
}
