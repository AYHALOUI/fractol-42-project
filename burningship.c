/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:33:26 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/17 19:15:29 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_burning_ship(t_fractol *fractol)
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

int	burning_ship_iter(double c_re, double c_im)
{
	double	z_real;
	double	z_img;
	double	z_real2;
	double	z_img2;
	int		nbr_iteration;

	z_real = 0;
	z_img = 0;
	nbr_iteration = 0;
	while (nbr_iteration < MAX_ITER)
	{
		z_real2 = z_real * z_real;
		z_img2 = z_img * z_img;
		if (z_real2 + z_img2 > 4)
			return (nbr_iteration);
		z_img = 2 * fabs(z_real * z_img) + c_im;
		z_real = z_real2 - z_img2 + c_re;
		nbr_iteration++;
	}
	return (MAX_ITER);
}

void	get_realimg_burningship(t_fractol *fractol,
	double x_repere, double y_repere)
{
	fractol->z_real = fractol->x + fractol->min_x + (x_repere
			* (fractol->max_x - fractol->min_x)) / WIDTH;
	fractol->z_real *= fractol->zoom;
	fractol->z_img = fractol->y + fractol->min_y + (y_repere
			* (fractol->max_y - fractol->min_y)) / HEIGHT;
	fractol->z_img *= fractol->zoom;
}

void	draw_burning_ship(t_fractol *fractol)
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
			get_realimg_burningship(fractol, x_repere, y_repere);
			if (nbr_iteration == MAX_ITER)
				color = 0;
			else
				color = nbr_iteration * fractol->color[fractol->color_index];
			nbr_iteration = burning_ship_iter(fractol->z_real, fractol->z_img);
			my_mlx_pixel_put(fractol, x_repere, y_repere, color);
		}
	}
}
