/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:50:57 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 14:28:01 by pscott           ###   ########.fr       */
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
	if (value < 0)
		ft_putchar('-');
	while (len < width)
	{
		ft_putchar(fill);
		width--;
	}
	if (value == -2147483648)
	{
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else
		value < 0 ? ft_putnbr(-value) : ft_putnbr(value);
}
