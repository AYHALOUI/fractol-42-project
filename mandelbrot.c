/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:33:38 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/17 19:12:09 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->min_x = -2.0;
	fractol->max_x = 2.0;
	fractol->min_y = -2.0;
	fractol->max_y = 2.0;
	fractol->x = 0;
	fractol->y = 0;
	fractol->zoom = 1;
	fractol->color[0] = LIGHTBLUE;
	fractol->color[1] = 0x0000FF;
	fractol->color[2] = 0xFF0000;
	fractol->color[3] = 0xF0EB8D;
	fractol->color[4] = 0x0C92C6D;
	fractol->color[5] = 0xF99417;
}

int	mandelbrot_iter(double c_real, double c_img)
{
	double	z_real;
	double	z_img;
	double	z_real2;
	double	z_img2;
	int		nbr_iterarion;

	z_real = 0;
	z_img = 0;
	nbr_iterarion = 0;
	while (nbr_iterarion < MAX_ITER)
	{
		z_real2 = z_real * z_real;
		z_img2 = z_img * z_img;
		if (z_real2 + z_img2 > 4)
			return (nbr_iterarion);
		z_img = 2 * z_real * z_img + c_img;
		z_real = z_real2 - z_img2 + c_real;
		nbr_iterarion++;
	}
	return (MAX_ITER);
}

void	get_realimg_mandelbrot(t_fractol *fractol,
	double x_repere, double y_repere)
{
	fractol->c_real = fractol->x + fractol->min_x
		+ (x_repere * (fractol->max_x - fractol->min_x)) / WIDTH;
	fractol->c_real *= fractol->zoom;
	fractol->c_img = fractol->y + fractol->min_y
		+ (y_repere * (fractol->max_y - fractol->min_y)) / HEIGHT;
	fractol->c_img *= fractol->zoom;
}

void	draw_mandelbrot(t_fractol *fractol)
{
	double		x_repere;
	double		y_repere;
	int			nbr_iteration;
	int			color;

	x_repere = -1;
	while (++x_repere < WIDTH)
	{
		y_repere = -1;
		while (++y_repere < HEIGHT)
		{
			get_realimg_mandelbrot(fractol, x_repere, y_repere);
			if (nbr_iteration == MAX_ITER)
				color = 0;
			else
				color = nbr_iteration * fractol->color[fractol->color_index];
			nbr_iteration = mandelbrot_iter(fractol->c_real, fractol->c_img);
			my_mlx_pixel_put(fractol, x_repere, y_repere, color);
		}
	}
}
