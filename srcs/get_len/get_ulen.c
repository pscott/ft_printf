/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ulen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:45:55 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 16:48:14 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_ulen(unsigned int value)
{
	int ulen;

	ulen = 0;
	while (value > 0)
	{
		ulen++;
		value /= 10;
	}
	return (ulen == 0 ? 1 : ulen);
}

int		get_ulllen(ULL value)
{
	int ulen;

	ulen = 0;
	while (value > 0)
	{
		ulen++;
		value /= 10;
	}
	return (ulen == 0 ? 1 : ulen);
}

int		get_ullen(UL value)
{
	int ulen;

	ulen = 0;
	while (value > 0)
	{
		ulen++;
		value /= 10;
	}
	return (ulen == 0 ? 1 : ulen);
}
