/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_lint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:05:56 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 20:03:39 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_lint_left(int perc_len, t_arg *specs, L value)
{
	char	sign;
	char	*nb;

	sign = value >= 0 ? '+' : '-';
	if (specs->plus || value < 0)
	{
		*specs->string = sign;
		increm_string(specs, 1);
		specs->data_len--;
		perc_len--;
	}
	while (specs->precision_len > specs->data_len)
	{
		*specs->string = '0';
		increm_string(specs, 1);
		specs->precision_len--;
		perc_len--;
	}
	nb = ft_itoa_spec(specs, value);
	if (!null_data(specs, (ULL) value))
		ft_strncat_move(nb, specs->data_len, specs);
	while (specs->data_len < perc_len)
	{
		*specs->string = ' ';
		perc_len--;
		increm_string(specs, 1);
	}
	free(nb);
}

static int		sign_len(t_arg *specs, L value)
{
	if (specs->plus)
		return (1);
	if (value < 0)
		return (1);
	return (0);
}

void	fill_lint(int perc_len, t_arg *specs, L value)
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
			increm_string(specs, 1);
		}
	}
	while (perc_len > max(specs->precision_len + sign_len(specs, value), specs->data_len))
	{
		*specs->string = specs->fill;
		increm_string(specs, 1);
		perc_len--;
	}
	if (sign_put)
	{
		*specs->string = sign;
		increm_string(specs, 1);
	}
	while (sign_len(specs, value) + specs->precision_len > specs->data_len)
	{
		*specs->string = '0';
		specs->precision_len--;
		increm_string(specs, 1);
	}
	nb = ft_itoa_spec(specs, value);
	ft_strncat_move(nb, specs->data_len - sign_len(specs, value), specs);
	free(nb);
}

void	format_lint(t_arg *specs, L value)
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
		increm_string(specs, 1);
		perc_len--;
	}
	if (specs->plus && value >= 0 && specs->data_len)
		specs->data_len++;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_lint_left(perc_len, specs, value);
	else
		fill_lint(perc_len, specs, value);
}
