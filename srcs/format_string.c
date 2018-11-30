/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:23:51 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 18:45:52 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_string(int perc_len, t_arg *specs, char *value)
{
	int		data_l;
	char	fill;

	if (specs->precision)
	{
		if (specs->data_len > specs->precision_len)
		{
			data_l = specs->precision_len;
			perc_len = 0;
		}
		else
			data_l = specs->data_len;
	}
	else
		data_l = specs->data_len > specs->precision_len ? specs->precision_len : specs->data_len;
	fill = specs->fill;
	while (data_l < perc_len)
	{
		*specs->string = fill;
		perc_len--;
		specs->string++;
	}
	ft_strncpy(specs->string, value, data_l);
	specs->string += data_l;
}

void	fill_string_left(int perc_len, t_arg *specs, char *value)
{
	int		data_l;
	char	fill;

	if (specs->precision)
	{
		if (specs->data_len > specs->precision_len)
		{
			data_l = specs->precision_len;
			perc_len = 0;
		}
		else
			data_l = specs->data_len;
	}
	else
		data_l = specs->data_len;
	ft_strncpy(specs->string, value, data_l);
	specs->string += data_l;
	fill = specs->fill;
	while (data_l < perc_len)
	{
		*specs->string = fill;
		perc_len--;
		specs->string++;
	}
}

void	format_string(t_arg *specs, char *value)
{
	int perc_len;

	perc_len = specs->width > specs->data_len ? specs->width : specs->data_len;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_string_left(perc_len, specs, value);
	else
		fill_string(perc_len, specs, value);
}
