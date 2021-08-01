/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:49:13 by antonmar          #+#    #+#             */
/*   Updated: 2021/08/01 19:11:29 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	mandelbrot_option(t_pos fractal_pos)
{
	fractal_pos.type = 'm';
	fractal_pos.vars = new_win(fractal_pos.width, fractal_pos.height);
	print_malderbrot(&fractal_pos);
	mlx_key_hook(fractal_pos.vars.win, key_hook, &fractal_pos);
	mlx_mouse_hook(fractal_pos.vars.win, mouse_hook, &fractal_pos);
	mlx_loop(fractal_pos.vars.mlx);
}

t_fractol	set_mandelbrot(t_fractol fractal, t_pos fractal_pos)
{
	fractal.creal = 1.5 * (fractal_pos.x - fractal_pos.width / 2)
		/ (fractal_pos.zoom * fractal_pos.width) + fractal_pos.move_x;
	fractal.cimg = (fractal_pos.y - fractal_pos.height / 2)
		/ (fractal_pos.zoom * fractal_pos.height) + fractal_pos.move_y;
	fractal.a = 0;
	fractal.b = 0;
	return (fractal);
}

int	i_mfractol(t_fractol fractal)
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

int	print_malderbrot(t_pos *fractal_pos)
{
	t_fractol	m_fractal;
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
			m_fractal = set_mandelbrot(m_fractal, *fractal_pos);
			i = i_mfractol(m_fractal);
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
