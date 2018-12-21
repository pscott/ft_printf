/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:22:44 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 17:18:54 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(ULL num, int base, char *rep)
{
	static char	buffer[80];
	char		*ptr;

	ptr = &buffer[80];
	*ptr = 0;
	ptr--;
	if (num == 0)
		*--ptr = rep[num & base];
	while (num)
	{
		*--ptr = rep[num % base];
		num /= base;
	}
	return (ptr);
}
