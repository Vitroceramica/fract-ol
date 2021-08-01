/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:04:38 by antonmar          #+#    #+#             */
/*   Updated: 2021/08/01 19:48:00 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(int argc, char *argv[])
{
	t_pos	fractal_pos;

	fractal_pos.width = 1280;
	fractal_pos.height = 960;
	fractal_pos.zoom = 0.3;
	fractal_pos.move_x = -0.5;
	fractal_pos.move_y = 0;
	fractal_pos.color = 0;
	if (argc <= 1)
	{
		printf("No has introducido nada \n");
		param_list();
		return (0);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		mandelbrot_option(fractal_pos);
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		julia_option(argc, argv, fractal_pos);
	else
	{
		printf("El comando introducido no es válido \n");
		param_list();
		return (0);
	}
	return (0);
}
