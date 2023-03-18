/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:33:34 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/17 19:27:10 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_functions(t_fractol fractol)
{
	mlx_put_image_to_window(fractol.mlx_ptr,
		fractol.win_ptr, fractol.img_ptr, 0, 0);
	mlx_mouse_hook(fractol.win_ptr, mouse_hook, &fractol);
	mlx_key_hook(fractol.win_ptr, key_hook, &fractol);
	mlx_hook(fractol.win_ptr, 17, 0, destroy, &fractol);
	mlx_hook(fractol.win_ptr, 2, 0, key_exit, &fractol);
	mlx_loop(fractol.mlx_ptr);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ft_fractol_name(av[1]) == -1)
		ft_wrong_fractal_type();
	fractol.fractal_name = ft_fractol_name(av[1]);
	init_mlx(&fractol);
	if (fractol.fractal_name == MANDELBROT)
	{
		init_mandelbrot(&fractol);
		draw_mandelbrot(&fractol);
	}
	else if (fractol.fractal_name == JULIA && ac == 4)
	{
		init_julia(&fractol, ft_atof(av[2]), ft_atof(av[3]));
		draw_julia(&fractol);
	}
	else if (fractol.fractal_name == BURNINGSHIP)
	{
		init_burning_ship(&fractol);
		draw_burning_ship(&fractol);
	}
	else
		ft_wrong_fractal_type();
	return (mlx_functions(fractol), 0);
}
