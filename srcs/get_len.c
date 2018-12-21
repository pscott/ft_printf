/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:51:01 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 18:33:36 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len(int value)
{
	int len;

	len = 0;
	if (value == -2147483648)
		return (11);
	if (value < 0)
	{
		len++;
		value = -value;
	}
	while (value > 0)
	{
		len++;
		value /= 10;
	}
	return (len == 0 ? 1 : len);
}

int		get_lllen(LL value)
{
	int len;

	len = 0;
	if ((ULL)value == -9223372036854775808U)
		return (20);
	if (value < 0)
	{
		len++;
		value = -value;
	}
	while (value > 0)
	{
		len++;
		value /= 10;
	}
	return (len == 0 ? 1 : len);
}

int		get_llen(L value)
{
	int len;

	len = 0;
	if (value < 0)
	{
		len++;
		value = -value;
	}
	while (value > 0)
	{
		len++;
		value /= 10;
	}
	return (len == 0 ? 1 : len);
}
