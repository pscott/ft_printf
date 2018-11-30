/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:45:26 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 15:45:14 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_char(int perc_len, t_arg *specs, char value)
{

	while (specs->data_len < perc_len)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
	*(specs->string) = value;
	specs->string++;
}

void	fill_char_left(int perc_len, t_arg *specs, char value)
{
	*(specs->string) = value;
	specs->string++;
	while (specs->data_len < perc_len)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
}

void	format_char(t_arg *specs, char value)
{
	int perc_len;

	specs->type = 'c';
	set_data_len(specs, value);
	perc_len = specs->width > 1 ? specs->width : 1;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_char_left(perc_len, specs, value);
	else
		fill_char(perc_len, specs, value);
}
