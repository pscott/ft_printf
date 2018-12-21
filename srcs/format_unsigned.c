/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 12:51:46 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 16:59:16 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_uint_left(int perc_len, t_arg *specs, ULL value)
{
	char	*nb;

	while (specs->precision_len > specs->data_len)
	{
		*specs->string = '0';
		increm_string(specs, 1);
		specs->precision_len--;
		perc_len--;
	}
	nb = ft_uitoa_spec(specs, value);
	if (!null_data(specs, (ULL) value))
	{
		ft_strncat_move(nb, specs->data_len, specs);
	}
	while (specs->data_len < perc_len)
	{
		*specs->string = ' ';
		perc_len--;
		increm_string(specs, 1);
	}
	free(nb);
}

static int	usign_len(t_arg *specs)
{
	if (specs->plus)
		return (1);
	return (0);
}

static void	fill_uint(int perc_len, t_arg *specs, ULL value)
{
	char	*nb;

	while (perc_len > max(specs->precision_len, specs->data_len))
	{
		*specs->string = specs->fill;
		increm_string(specs, 1);
		perc_len--;
	}
	while (specs->precision_len > specs->data_len)
	{
		*specs->string = '0';
		specs->precision_len--;
		increm_string(specs, 1);
	}
	nb = ft_uitoa_spec(specs, value);
	ft_strncat_move(nb, specs->data_len - usign_len(specs), specs);
	free(nb);
}

void	format_unsigned(t_arg *specs, ULL value)
{
	int		 perc_len;

	set_data_len(specs, value);
	if (null_data(specs, (ULL) value && !specs->plus))
		specs->data_len = 0;
	if (specs->precision_len > specs->width_len)
	{
		perc_len = max(specs->data_len, specs->precision_len);
		specs->fill = '0';
	}
	else
		perc_len = max(specs->data_len, specs->width_len);
	if (specs->plus && specs->data_len)
		specs->data_len++;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_uint_left(perc_len, specs, value);
	else
		fill_uint(perc_len, specs, value);
}
