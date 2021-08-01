/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:21:50 by antonmar          #+#    #+#             */
/*   Updated: 2021/08/01 19:26:46 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_r(int trgb)
{
	return (trgb >> 16);
}

int	get_g(int trgb)
{
	return (trgb >> 8);
}

int	get_b(int trgb)
{
	return (trgb >> 0);
}

int	move_color(int value, int color)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	r = value * value + r;
	g = value * value + g;
	b = value * value + b;
	return (create_trgb(0, r, g, b));
}
