/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:23:51 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 11:58:59 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_string(t_arg *specs, char *value)
{
	int		data_l;
	int		perc_len;
	char	fill;

	data_l = specs->precision ? min(specs->precision_len, specs->data_len) : specs->data_len;
	if (*value == 0)
		data_l = 0;
	perc_len = max(specs->width_len, data_l);
	fill = specs->fill;
	while (data_l < perc_len)
	{
		*specs->string = fill;
		perc_len--;
		specs->string++;
	}
	ft_strncat_move(specs->string, value, data_l, specs);
}

static void	fill_string_left(t_arg *specs, char *value)
{
	int		data_l;
	int		perc_len;
	char	fill;

	data_l = specs->precision ? min(specs->precision_len, specs->data_len) : specs->data_len;
	if (*value == 0)
		data_l = 0;
	perc_len = max(specs->width_len, data_l);
	ft_strncat_move(specs->string, value, data_l, specs);
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
	char *nil;

	nil = "(null)";
	//perc_len = specs->width > specs->data_len ? specs->width : specs->data_len;
	if (value == NULL)
	{
		value = nil;
		specs->data_len = 6;
	}
	if (specs->l == 1)
	{
		specs->origin = NULL;
		write(1, "\n", 1);
		return ;
	}
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_string_left(specs, value);
	else
		fill_string(specs, value);
}
