/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:50:57 by pscott            #+#    #+#             */
/*   Updated: 2018/11/27 18:19:33 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		plus_or_left(t_arg *specs, int value)
{
	if (value >= 0 && (specs->left || specs->plus))
		return (1);
	return (0);
}

void	print_int(t_arg *specs, int value)
{
	int len;
	int width;
	char fill;

	if (specs->l)
		value = (unsigned long)value;
	len = plus_or_left(specs, value) ? get_len(value) + 1 : get_len(value);
	width = specs->width;
	fill = specs->fill;
	if (specs->left && print_int_left(specs, value, len, width))
		return ;
	if (value < 0 && specs->fill == '0')
		ft_putchar('-');
	if (value >= 0 && specs->fill == '0' && specs->plus)
		ft_putchar('+');
	while (len < width)
	{
		ft_putchar(fill);
		width--;
	}
	if (value < 0 && specs->fill != '0')
		ft_putchar('-');
	if (value >= 0 && specs->fill != '0' && specs->plus)
	{
		ft_putchar('+');
	}
	if (value == -2147483648)
	{
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else
		value < 0 ? ft_putnbr(-value) : ft_putnbr(value);
}

int		print_int_left(t_arg *specs, int value, int len, int width)
{
	if (specs->plus && !specs->left)
		return (0);
	if (specs->plus && value >= 0)
		ft_putchar('+');
	ft_putnbr(value);
	while (len < width)
	{
		ft_putchar(' ');
		width--;
	}
	return (1);
}
