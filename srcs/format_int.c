/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:11:35 by pscott            #+#    #+#             */
/*   Updated: 2018/11/29 11:06:48 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_blanks(int perc_len, t_arg *specs, LL value)
{
	char sign;
	char *tmp;

	tmp = specs->string;
	sign = value >= 0 ? '+' : '-';
	if (specs->fill == '0')
	{
		if (specs->plus || value < 0)
		{
			*specs->string = sign;
			specs->string++;
		}
	}
	while (specs->nb_len < perc_len)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
	if (specs->fill == ' ')
	{
		*specs->string = sign;
	}
	specs->string = tmp;
}

void	format_int(t_arg *specs, LL value)
{
	int		 perc_len;

	specs->nb_len = get_len(value);
	perc_len = max(specs->nb_len, specs->width);
	if (specs->plus && value >= 0)
		specs->nb_len++;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	fill_blanks(perc_len, specs, value);
}
