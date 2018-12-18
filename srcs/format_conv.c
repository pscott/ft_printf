/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:27:22 by pscott            #+#    #+#             */
/*   Updated: 2018/12/18 11:54:44 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_string(t_arg *specs, char *value)
{
	int		data_l;
	int		perc_len;
	char	fill;

	check_conv_value(specs, value);
	data_l = specs->data_len;
	perc_len = max(specs->width_len, data_l);
	fill = specs->fill;
	put_ox(specs, value, &perc_len, 0);
	while ((data_l != 0 || specs->width)
			&& perc_len > max(specs->precision_len, data_l)
			+ (specs->fill != '0' && specs->hash && value[0] != '0') * 2)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
	put_ox(specs, value, &perc_len, 1);
	while (specs->precision_len > data_l)
	{
		*specs->string = '0';
		specs->precision_len--;
		specs->string++;
	}
	ft_strncat_move(specs->string, value, data_l, specs);
}

static void		fill_string_left(t_arg *specs, char *value)
{
	int		data_l;
	int		perc_len;

	check_conv_value(specs, value);
	data_l = specs->data_len;
	perc_len = max(specs->width_len, data_l);
	put_ox(specs, value, &perc_len, 2);
	while (specs->precision_len > data_l)
	{
		*specs->string = '0';
		specs->precision_len--;
		specs->string++;
		perc_len--;
	}
	ft_strncat_move(specs->string, value, data_l, specs);
	while ((data_l != 0 || specs->width)
			&& perc_len > max(specs->precision_len, data_l) +
			(specs->fill != '0' && specs->hash && value[0] != '0') * 2)
	{
		*specs->string = ' ';
		perc_len--;
		specs->string++;
	}
}

void			format_conv(t_arg *specs, char *value)
{
	char *nil;

	nil = "(null)";
	if (value == NULL)
	{
		value = nil;
		specs->data_len = 6;
	}
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_string_left(specs, value);
	else
		fill_string(specs, value);
}
