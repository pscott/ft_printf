/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:50:57 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 18:44:49 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_arg *specs, int value)
{
	int len;
	int width;
	char fill;

	len = get_len(value);
	width = specs->width;
	fill = specs->fill;
	if (print_int_minus(specs, value, len, width))
		return ;
	if (value < 0 && specs->fill == '0')
		ft_putchar('-');
	if (value >= 0 && specs->fill == '0' && specs->plus)
	{
		ft_putchar('+');
		len++;
	}
	while (len < width)
	{
		ft_putchar(fill);
		width--;
	}
	if (value < 0 && specs->fill != '0')
		ft_putchar('-');
	if (value >= 0 && specs->fill != '0' && specs->plus)
		ft_putchar('+');
	if (value == -2147483648)
	{
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else
		value < 0 ? ft_putnbr(-value) : ft_putnbr(value);
}

int		print_int_minus(t_arg *specs, int value, int len, int width)
{
	char fill;

	fill = specs->fill;
	if (specs->left || specs->plus)
		return (0);
	ft_putnbr(value);
	while (len < width)
	{
		ft_putchar(fill);
		width--;
	}
	return (1);
}
