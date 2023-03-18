/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:41:04 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/17 17:41:10 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
			WIDTH, HEIGHT, "fractol");
	fractol->img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	fractol->addr_img = mlx_get_data_addr(fractol->img_ptr,
			&fractol->bits_per_pixel, &fractol->line_length, &fractol->endian);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*pixel;

	pixel = fractol->addr_img + (y
			* fractol->line_length + x * (fractol->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int	ft_fractol_name(char *fractol_name)
{
	if (!fractol_name)
		exit (0);
	if (!ft_strcmp(fractol_name, "mandelbrot"))
		return (MANDELBROT);
	else if (!ft_strcmp(fractol_name, "julia"))
		return (JULIA);
	else if (!ft_strcmp(fractol_name, "burningship"))
		return (BURNINGSHIP);
	else
		return (INVALID);
}

int	key_exit(int key, t_fractol *fractol)
{
	if (key == 53)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
		exit(0);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
