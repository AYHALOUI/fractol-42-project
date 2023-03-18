/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:33:31 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/17 19:10:20 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractol *fractol, double c_real, double c_img)
{
	fractol->min_x = -2.0;
	fractol->max_x = 2.0;
	fractol->min_y = -2.0;
	fractol->max_y = 2.0;
	fractol->x = 0;
	fractol->y = 0;
	fractol->zoom = 1;
	fractol->c_real = c_real;
	fractol->c_img = c_img;
	fractol->color[0] = LIGHTBLUE;
	fractol->color[1] = 0x0000FF;
	fractol->color[2] = 0xFF0000;
	fractol->color[3] = 0xF0EB8D;
	fractol->color[4] = 0x0C92C6D;
	fractol->color[5] = 0xF99417;
}

int	julia_iter(t_fractol *fractol)
{
	int	nbr_iteration;

	nbr_iteration = 0;
	while (nbr_iteration < MAX_ITER)
	{
		fractol->temp_value = fractol->z_real;
		fractol->z_real = fractol->z_real * fractol->z_real
			- fractol->z_img * fractol->z_img + fractol->c_real;
		fractol->z_img = 2 * fractol->z_img
			* fractol->temp_value + fractol->c_img;
		if (fractol->z_real * fractol->z_real
			+ fractol->z_img * fractol->z_img > 4)
			return (nbr_iteration);
		nbr_iteration++;
	}
	return (MAX_ITER);
}

void	get_realimg_julia(t_fractol *fractol, double x_repere, double y_repere)
{
	fractol->z_real = fractol->x + fractol->min_x + (x_repere
			* (fractol->max_x - fractol->min_x)) / WIDTH;
	fractol->z_real *= fractol->zoom;
			fractol->z_img = fractol->y + fractol->min_y + (y_repere
			* (fractol->max_y - fractol->min_y)) / HEIGHT;
	fractol->z_img *= fractol->zoom;
}

void	draw_julia(t_fractol *fractol)
{
	double	x_repere;
	double	y_repere;
	int		nbr_iteration;
	int		color;

	x_repere = -1;
	while (++x_repere < WIDTH)
	{
		y_repere = -1;
		while (++y_repere < HEIGHT)
		{
			get_realimg_julia(fractol, x_repere, y_repere);
			if (nbr_iteration == MAX_ITER)
				color = 0;
			else
				color = nbr_iteration * fractol->color[fractol->color_index];
			nbr_iteration = julia_iter(fractol);
			my_mlx_pixel_put(fractol, x_repere, y_repere, color);
		}
	}
}
