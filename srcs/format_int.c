/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:11:35 by pscott            #+#    #+#             */
/*   Updated: 2018/12/14 16:15:13 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_int_left(int perc_len, t_arg *specs, LL value)
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
	nb = ft_itoa_spec(specs, value);
	ft_strcat(specs->string, nb);
	specs->string += specs->data_len;
	while (specs->data_len < perc_len)
	{
		*specs->string = ' ';
		perc_len--;
		specs->string++;
	}
	free(nb);
}

int		sign_len(t_arg *specs, LL value)
{
	if (specs->plus)
		return (1);
	if (value < 0)
		return (1);
	return (0);
}

void	fill_int(int perc_len, t_arg *specs, LL value)
{
	char	sign;
	char	*nb;

	sign = value >= 0 ? '+' : '-';
	if (specs->fill == '0')
	{
		if (specs->plus || value < 0)
		{
			*specs->string = sign;
			specs->string++;
		}
	}
	while (specs->data_len < perc_len)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
	if (specs->fill == ' ')
	{
		if (specs->plus || value < 0)
		{
			*specs->string = sign;
			specs->string++;
		}
	}
	nb = ft_itoa_spec(specs, value);
	ft_strcat(specs->string, nb);
	specs->string += specs->data_len - sign_len(specs, value);
	free(nb);
}



void	format_int(t_arg *specs, LL value)
{
	int		 perc_len;

	set_data_len(specs, value);
	perc_len = max(specs->data_len, specs->width);
	if (specs->extra && value > 0)
	{
		*specs->string = ' ';
		specs->string++;
		perc_len--;
	}
	if (specs->plus && value >= 0)
		specs->data_len++;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_int_left(perc_len, specs, value);
	else
		fill_int(perc_len, specs, value);
}
