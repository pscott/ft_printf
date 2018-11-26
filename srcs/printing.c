/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:50:57 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 13:18:25 by pscott           ###   ########.fr       */
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
	while (len < width)
	{
		ft_putchar(fill);
		width--;
	}
	ft_putnbr(value);
}
