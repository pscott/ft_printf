/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:27:22 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 17:49:41 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_string(t_arg *specs, char *value)
{
	int		data_l;
	int		perc_len;

	check_conv_value(specs, value);
	data_l = specs->data_len;
	perc_len = max(specs->width_len, data_l);
	put_ox(specs, value, &perc_len, 0);
	while ((data_l != 0 || specs->width)
			&& perc_len > max(specs->precision_len, data_l)
			+ (specs->fill != '0' && specs->hash && value[0] != '0')
			* ox_len(specs))
	{
		*specs->string = specs->fill;
		perc_len--;
		increm_string(specs, 1);
	}
	put_ox(specs, value, &perc_len, 1);
	ft_special_memset(specs, '0', specs->precision_len - data_l);
	ft_strncat_move(value, data_l, specs);
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
		increm_string(specs, 1);
		perc_len--;
	}
	ft_strncat_move(value, data_l, specs);
	while ((data_l != 0 || specs->width)
			&& perc_len > max(specs->precision_len, data_l) +
			(specs->fill != '0' && specs->hash && value[0] != '0')
			* ox_len(specs))
	{
		*specs->string = ' ';
		perc_len--;
		increm_string(specs, 1);
	}
}

void			format_conv(t_arg *specs, char *value)
{
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_string_left(specs, value);
	else
		fill_string(specs, value);
}
