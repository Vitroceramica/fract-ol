/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:49:48 by antonmar          #+#    #+#             */
/*   Updated: 2021/08/01 18:15:31 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_fractol {
	double	a;
	double	prea;
	double	b;
	double	preb;
	double	creal;
	double	cimg;
}				t_fractol;

typedef struct s_pos {
	t_data	img;
	t_vars	vars;
	int		color;
	int		height;
	int		width;
	char	type;
	double	x;
	double	y;
	double	zoom;
	double	creal;
	double	cimg;
	double	move_x;
	double	move_y;
}				t_pos;

int		ft_strncmp(const char *str1, const char *str2, size_t n);
float	ft_fatoi(const char *str);
int		create_trgb(int t, int r, int g, int b);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		get_opposite(int color);
int		add_shade(double distance, int color);
int		variate_color(int keycode, int color);
int		move_color(int value, int color);
void	ft_putpixel(t_data *data, int x, int y, int color);
int		mouse_hook(int button, int x, int y, t_pos *fractal);
int		key_hook(int keycode, t_pos *fractal);
int		print_malderbrot(t_pos *fractal_pos);
void	mandelbrot_option(t_pos fractal_pos);
int		print_julia(t_pos *fractal_pos);
void	julia_option(int argc, char **argv, t_pos fractal_pos);
void	param_list(void);
t_vars	new_win(int width, int height);
t_data	new_img(t_vars vars, int width, int height);

#endif