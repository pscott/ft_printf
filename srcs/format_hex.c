/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:04:45 by pscott            #+#    #+#             */
/*   Updated: 2018/12/17 19:08:28 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_string(t_arg *specs, char *value)
{
	int		data_l;
	int		perc_len;
	char	fill;

	data_l = specs->data_len;
	perc_len = max(specs->width_len, data_l);
	if (value[0] == '0' && specs->precision && specs->precision_len == 0)
		data_l = 0;
	fill = specs->fill;
	if (specs->fill == '0' && specs->hash && value[0] != '0')
	{
		ft_strncat(specs->string, ox_helper(specs), 2);
		specs->string += 2;
		perc_len -= 2;
	}
	while ((data_l != 0 || specs->width) && perc_len > max(specs->precision_len, data_l) + (specs->fill != '0' && specs->hash && value[0] != '0') * 2)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
	if (specs->fill != '0' && specs->hash && value[0] != '0')
	{
		ft_strncat(specs->string, ox_helper(specs), 2);
		specs->string += 2;
	}
	while (specs->precision_len > data_l)
	{
		*specs->string = '0';
		specs->precision_len--;
		specs->string++;
	}
	ft_strncat(specs->string, value, data_l);
	specs->string += data_l;
}

static void	fill_string_left(t_arg *specs, char *value)
{
	int		data_l;
	int		perc_len;

	data_l = specs->data_len;
	if (*value == 0)
		data_l = 0;
	perc_len = max(specs->width_len, data_l);
	if (specs->hash && value[0] != '0')
	{
		ft_strncat(specs->string, ox_helper(specs), 2);
		specs->string += 2;
		perc_len -= 2;
	}
	while (specs->precision && perc_len > min(specs->precision_len, specs->data_len) + (specs->hash && value[0] != '0') * 2)
	{
		*specs->string = '0';
		specs->string++;
		specs->precision_len--;
		perc_len--;
	}
	ft_strncat(specs->string, value, data_l);
	specs->string += data_l;
	while (data_l < perc_len)
	{
		*specs->string = ' ';
		perc_len--;
		specs->string++;
	}
}

void	format_hex(t_arg *specs, char *value)
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
