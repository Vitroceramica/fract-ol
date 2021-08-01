/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:24:43 by antonmar          #+#    #+#             */
/*   Updated: 2021/08/01 19:17:45 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_vars	new_win(int width, int height)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "Fractol");
	return (vars);
}

t_data	new_img(t_vars vars, int width, int height)
{
	t_data	img;

	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	ft_putpixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mouse_hook(int button, int x, int y, t_pos *fractal)
{
	if (button == 5)
	{
		fractal->zoom += 0.1 * fractal->zoom;
		if (x > 640)
			fractal->move_x += (x - 640) * 0.001 / (fractal->zoom * 2);
		else
			fractal->move_x -= (640 - x) * 0.001 / (fractal->zoom * 2);
		if (y > 480)
			fractal->move_y -= (y - 480) * 0.001 / (fractal->zoom * 2);
		else
			fractal->move_y += (480 - y) * 0.001 / (fractal->zoom * 2);
	}
	if (button == 4 && fractal->zoom > 0.1)
		fractal->zoom -= 0.1 * fractal->zoom;
	if (fractal->type == 'm')
		print_malderbrot(fractal);
	else if (fractal->type == 'j')
		print_julia(fractal);
	return (0);
}

int	key_hook(int keycode, t_pos *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->vars.mlx, fractal->vars.win);
		exit(0);
	}
	if (keycode == 126)
		fractal->move_y -= 0.1 / fractal->zoom;
	if (keycode == 125)
		fractal->move_y += 0.1 / fractal->zoom;
	if (keycode == 124)
		fractal->move_x += 0.1 / fractal->zoom;
	if (keycode == 123)
		fractal->move_x -= 0.1 / fractal->zoom;
	fractal->color = variate_color(keycode, fractal->color);
	if (fractal->type == 'm')
		print_malderbrot(fractal);
	if (fractal->type == 'j')
		print_julia(fractal);
	return (0);
}
