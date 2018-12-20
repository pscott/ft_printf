/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:11:35 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 18:30:10 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_int_left(int perc_len, t_arg *specs, int value)
{
	char	sign;
	char	*nb;

	sign = value >= 0 ? '+' : '-';
	if (specs->plus || value < 0)
	{
		*specs->string = sign;
		specs->string++;
		specs->data_len--;
		perc_len--;
	}
	while (specs->precision_len > specs->data_len)
	{
		*specs->string = '0';
		specs->string++;
		specs->precision_len--;
		perc_len--;
	}
	nb = ft_itoa_spec(specs, value);
	if (!null_data(specs, (ULL) value))
		ft_strncat_move(specs->string, nb, specs->data_len, specs);
	while (specs->data_len < perc_len)
	{
		*specs->string = ' ';
		perc_len--;
		specs->string++;
	}
	free(nb);
}

static int		sign_len(t_arg *specs, int value)
{
	if (specs->plus)
		return (1);
	if (value < 0)
		return (1);
	return (0);
}

void	fill_int(int perc_len, t_arg *specs, int value)
{
	char	sign;
	char	*nb;
	int		sign_put;

	sign = value >= 0 ? '+' : '-';
	sign_put = sign_len(specs, value);
	if (specs->fill == '0')
	{
		if (sign_put)
		{
			*specs->string = sign;
			sign_put = 0;
			specs->string++;
		}
	}
	while (perc_len > max(specs->precision_len + sign_len(specs, value), specs->data_len))
	{
		*specs->string = specs->fill;
		specs->string++;
		perc_len--;
	}
	if (sign_put)
	{
		*specs->string = sign;
		specs->string++;
	}
	while (sign_len(specs, value) + specs->precision_len > specs->data_len)
	{
		*specs->string = '0';
		specs->precision_len--;
		specs->string++;
	}
	nb = ft_itoa_spec(specs, value);
	ft_strncat_move(specs->string, nb, specs->data_len - sign_len(specs, value), specs);
	free(nb);
}

void	format_int(t_arg *specs, int value)
{
	int		 perc_len;

	set_data_len(specs, value);
	if (null_data(specs, (ULL) value) && !specs->plus)
		specs->data_len = 0;
	if (specs->precision_len > specs->width_len)
	{
		perc_len = max(specs->data_len, specs->precision_len);
		specs->fill = '0';
	}
	else
		perc_len = max(specs->data_len, specs->width_len);
	if (specs->extra && value > 0 && !specs->plus)
	{
		*specs->string = ' ';
		specs->string++;
		perc_len--;
	}
	if (specs->plus && value >= 0 && specs->data_len)
		specs->data_len++;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_int_left(perc_len, specs, value);
	else
		fill_int(perc_len, specs, value);
}
