/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:45:26 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 16:55:03 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_char(int perc_len, t_arg *specs, char *value)
{
	int		data_l;
	char	fill;

	data_l = specs->data_len;
	fill = specs->fill;
	while (data_l < perc_len)
	{
		*specs->string = fill;
		perc_len--;
		increm_string(specs, 1);
	}
	ft_strncat_move(value, 1, specs);
}

void	fill_char_left(int perc_len, t_arg *specs, char *value)
{
	int		data_l;

	data_l = specs->data_len;
	ft_strncat_move(value, 1, specs);
	while (data_l < perc_len)
	{
		*specs->string = ' ';
		perc_len--;
		increm_string(specs, 1);
	}
}

void	format_char(t_arg *specs, char *value)
{
	int perc_len;

	specs->data_len = 1;
	perc_len = specs->width_len > specs->data_len ? specs->width_len : specs->data_len;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_char_left(perc_len, specs, value);
	else
		fill_char(perc_len, specs, value);
}
