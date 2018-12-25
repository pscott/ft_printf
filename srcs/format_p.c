/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:27:22 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 17:49:41 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_string(t_arg *specs, L value)
{
	int		data_l;
	int		perc_len;

	data_l = specs->data_len;
	perc_len = max(specs->width_len, data_l);
//	put_px(specs, value, &perc_len);
	while ((data_l != 0 || specs->width)
			&& perc_len > max(specs->precision_len, data_l)
			+ (specs->fill != '0' && specs->hash && value != '0')
			* ox_len(specs))
	{
		*specs->string = specs->fill;
		perc_len--;
		increm_string(specs, 1);
	}
	put_px(specs, value, &perc_len);
	ft_special_memset(specs, '0', specs->precision_len - data_l);
	ft_strncat_move(specs->conv_val, data_l, specs);
}

static void		fill_string_left(t_arg *specs, L value)
{
	int		data_l;
	int		perc_len;

	data_l = specs->data_len;
	perc_len = max(specs->width_len, data_l);
	put_px(specs, value, &perc_len);
	while (specs->precision_len > data_l)
	{
		*specs->string = '0';
		specs->precision_len--;
		increm_string(specs, 1);
		perc_len--;
	}
	ft_strncat_move(specs->conv_val, data_l, specs);
	while ((data_l != 0 || specs->width)
			&& perc_len > max(specs->precision_len, data_l) +
			(specs->fill != '0' && specs->hash && value != '0')
			* ox_len(specs))
	{
		*specs->string = ' ';
		perc_len--;
		increm_string(specs, 1);
	}
}

void			format_p(t_arg *specs, L value)
{
	specs->conv_val = convert_p(value, 16, BASE_16_LOW);
	specs->data_len = ft_strlen(specs->conv_val);
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_string_left(specs, value);
	else
		fill_string(specs, value);
}
