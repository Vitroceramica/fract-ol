/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 18:12:48 by antonmar          #+#    #+#             */
/*   Updated: 2021/08/01 19:26:50 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	variate_color(int keycode, int color)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	if (keycode == 15)
		color = (r + 10) << 16;
	if (keycode == 5)
		color = (g + 10) << 8;
	if (keycode == 11)
		color = (b + 10) << 0;
	return (color);
}
