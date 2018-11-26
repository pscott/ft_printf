/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:42:16 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 13:05:54 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_move(char **str)
{
	size_t	i;
	int		modif;
	int		finalnb;

	i = 0;
	modif = 1;
	finalnb = 0;
	while (**str == '\t' || **str == '\r' || **str == '\v' || **str == '\b'
			|| **str == '\f' || **str == '\n' || **str == ' ')
		(*str)++;
	if (**str == '-')
	{
		(*str)++;
		modif = -1;
	}
	if (**str == '+' && modif != -1)
		(*str)++;
	while (ft_isdigit(**str))
	{
		finalnb = finalnb * 10 + **str - '0';
		(*str)++;
	}
	return (finalnb * modif);
}
