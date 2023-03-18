/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:06:00 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/17 17:46:26 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	help_ft_atof(char *str, double *result, double *power)
{
	while (*str >= '0' && *str <= '9')
	{
		*result = *result * 10 + (*str - '0');
		*power *= 10;
		str++;
	}
}

void	choose_fractal(t_fractol *fractal, double c_real, double c_img)
{
	(void)(c_real);
	(void)(c_img);
	if (fractal->fractal_name == MANDELBROT)
		draw_mandelbrot(fractal);
	else if (fractal->fractal_name == JULIA)
		draw_julia(fractal);
	else if (fractal->fractal_name == BURNINGSHIP)
		draw_burning_ship(fractal);
	else
		ft_wrong_fractal_type();
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

double	ft_atof(char *str)
{
	double	result;
	double	sign;
	double	power;

	result = 0;
	sign = 1;
	power = 1;
	if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
		return (0);
	while (is_white_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	help_ft_atof(str, &result, &power);
	return (result * sign / power);
}
