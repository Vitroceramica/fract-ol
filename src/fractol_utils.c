/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:01:40 by antonmar          #+#    #+#             */
/*   Updated: 2021/08/01 19:26:51 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] != '\0'
		&& str2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

long	find_simb(const char *str, int i)
{
	long	simb;

	simb = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			simb = -1;
	}
	return (simb);
}

float	point_num(const char *str)
{
	float	dec;
	float	mult;
	int		i;

	dec = 0;
	i = 0;
	mult = 0.1;
	while (str[i] != '.' && str[i])
		i++;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		dec = (str[i] - 48) * mult + dec;
		mult *= 0.1;
		i++;
	}
	return (dec);
}

float	ft_fatoi(const char *str)
{
	int		i;
	float	res;
	float	dec;
	long	simb;

	if (!str)
		return (0);
	res = 0;
	dec = 0;
	i = 0;
	simb = 1;
	while (str[i] == ' ')
		i++;
	simb = find_simb(str, i);
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = str[i] - 48 + res * 10;
		i++;
	}
	dec = point_num(str);
	res = (res + dec) * simb;
	return (res);
}

void	param_list(void)
{
	printf("  -Para visualizar el set de mandelbrot escribe ");
	printf("\"mandelbrot\" \n  -Para visualizar el set ");
	printf("de julia escribe \"julia\" \n  Si deseas generar un conjunto de ");
	printf("julia distinto escribe \"julia\" seguido de ");
	printf("los parámetros para generar el conjunto");
}
