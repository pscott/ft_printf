/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:15:28 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 14:40:33 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		valid_flags(char **format)
{
	char c;

	c = **format;
	if (c == '-' || c == '+' || c == '#' || c == '0' || c == ' ')
		return (1);
	return (0);
}

int		is_valid_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'i' || c == 'x' \
			|| c == 'X' || c == 'u' || c == '%')
		return (1);
	return (0);
}

int		max(int a, int b)
{
	return (a < b ? b : a);
}
