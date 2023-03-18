/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:34:26 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/17 19:25:07 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <complex.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 50

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define INVALID -1
# define LIGHTBLUE 0xffffff

# define BLUE  0x3A98B9
# define BEIGE 0xFFF1DC
# define GREY  0xFFF1DC

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr_img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	zoom;
	double	c_real;
	double	c_img;
	double	z_real;
	double	z_img;
	double	temp_value;
	double	x;
	double	y;
	int		fractal_name;
	short	color_index;
	int		color[6];
}				t_fractol;

// utils1 functions
void	help_ft_atof(char *str, double *result, double *power);
int		ft_strcmp(char *s1, char *s2);
double	ft_atof(char *str);
void	choose_fractal(t_fractol *fractal, double c_real, double c_img);

// utils functions
void	init_mlx(t_fractol *t_fractal);
void	my_mlx_pixel_put(t_fractol *fractal, int x, int y, int color);
int		ft_fractol_name(char *fractal_name);
void	ft_wrong_fractal_type(void);
int		key_exit(int key, t_fractol *fractal);

// mandelbrot file
void	init_mandelbrot(t_fractol *t_fractal);
int		mandelbrot_iter(double c_re, double c_im);
void	draw_mandelbrot(t_fractol *t_fractal);
void	get_realimg_mandelbrot(t_fractol *fractol,
			double x_repere, double y_repere);

// julia file
void	init_julia(t_fractol *t_fractal, double c_real, double c_img);
int		julia_iter(t_fractol *t_fractal);
void	draw_julia(t_fractol *t_fractal);
void	get_realimg_julia(t_fractol *fractol, double x_repere, double y_repere);

// burning_ship file 
void	init_burning_ship(t_fractol *t_fractal);
int		burning_ship_iter(double c_re, double c_im);
void	draw_burning_ship(t_fractol *t_fractal);
void	get_realimg_burningship(t_fractol *fractol,
			double x_repere, double y_repere);

// utils2 functions
int		destroy(t_fractol *fractal);
int		key_hook(int keycode, t_fractol *fractal);
int		mouse_hook(int button, int x, int y, t_fractol *fractal);
void	ft_putstr(char *str);
void	help_key_hook(int keycode, t_fractol *fractal);

#endif