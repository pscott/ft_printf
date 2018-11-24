/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:22:44 by pscott            #+#    #+#             */
/*   Updated: 2018/11/24 16:19:20 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(unsigned int num, int base)
{
	static char	*rep = "0123456789abcdef";
	static char	buffer[50];
	char		*ptr;

	// buffer[50], maybe get proper length ?
	ptr = &buffer[50];
	*ptr = 0;
	ptr--;
	while (num)
	{
		*--ptr = rep[num%base];
		num /= base;
	}
	return (ptr);
}
