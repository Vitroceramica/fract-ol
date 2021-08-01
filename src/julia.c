/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:48:27 by antonmar          #+#    #+#             */
/*   Updated: 2021/08/01 19:26:57 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	julia_option(int argc, char **argv, t_pos fractal_pos)
{
	if (argc > 2)
	{
		fractal_pos.creal = ft_fatoi(argv[2]);
		fractal_pos.cimg = ft_fatoi(argv[3]);
	}
	else
	{
		fractal_pos.creal = -0.835;
		fractal_pos.cimg = -0.232;
	}
	fractal_pos.type = 'j';
	fractal_pos.vars = new_win(fractal_pos.width, fractal_pos.height);
	print_julia(&fractal_pos);
	mlx_key_hook(fractal_pos.vars.win, key_hook, &fractal_pos);
	mlx_mouse_hook(fractal_pos.vars.win, mouse_hook, &fractal_pos);
	mlx_loop(fractal_pos.vars.mlx);
}

t_fractol	set_julia(t_fractol fractal, t_pos fractal_pos)
{
	fractal.creal = fractal_pos.creal;
	fractal.cimg = fractal_pos.cimg;
	fractal.a = 1.5 * (fractal_pos.x - fractal_pos.width / 2)
		/ (fractal_pos.zoom * fractal_pos.width) + fractal_pos.move_x;
	fractal.b = (fractal_pos.y - fractal_pos.height / 2)
		/ (fractal_pos.zoom * fractal_pos.height) + fractal_pos.move_y;
	return (fractal);
}

int	i_jfractol(t_fractol fractal)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		fractal.prea = fractal.a;
		fractal.preb = fractal.b;
		fractal.a = fractal.prea * fractal.prea - fractal.preb * fractal.preb
			+ fractal.creal;
		fractal.b = 2 * fractal.prea * fractal.preb + fractal.cimg;
		if ((fractal.a * fractal.a + fractal.b * fractal.b) > 4.0f)
			break ;
		i++;
	}
	return (i);
}

int	print_julia(t_pos *fractal_pos)
{
	t_fractol	j_fractal;
	int			i;

	fractal_pos->x = 0;
	i = 0;
	fractal_pos->img = new_img(fractal_pos->vars, fractal_pos->width,
			fractal_pos->height);
	while (fractal_pos->x < fractal_pos->width)
	{
		fractal_pos->y = 0;
		while (fractal_pos->y < fractal_pos->height)
		{
			j_fractal = set_julia(j_fractal, *fractal_pos);
			i = i_jfractol(j_fractal);
			if (i != 50)
				ft_putpixel(&fractal_pos->img, fractal_pos->x, fractal_pos->y,
					move_color(i, fractal_pos->color));
			fractal_pos->y++;
		}
		fractal_pos->x++;
	}
	mlx_put_image_to_window(fractal_pos->vars.mlx, fractal_pos->vars.win,
		fractal_pos->img.img, 0, 0);
	mlx_destroy_image(fractal_pos->vars.mlx, fractal_pos->img.img);
	return (0);
}
