/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:11:35 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 16:52:02 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_unsigned_left(int perc_len, t_arg *specs, ULL value)
{
	char	*nb;
	int		data_l;

	nb = ft_itoa_spec(specs, value);
	ft_strcat(specs->string, nb);
	specs->string += specs->data_len;
	data_l = specs->data_len;
	while (specs->data_len < perc_len)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
	free(nb);
}

void	fill_unsigned(int perc_len, t_arg *specs, ULL value)
{
	char	*nb;
	int		data_l;

	data_l = specs->data_len;
	while (data_l < perc_len)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
	nb = ft_itoa_spec(specs, value);
	ft_strcat(specs->string, nb);
	specs->string += specs->data_len;
	free(nb);
}

void	format_unsigned(t_arg *specs, ULL value)
{
	int		 perc_len;

	set_data_len(specs, value);
	perc_len = max(specs->data_len, specs->width);
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_unsigned_left(perc_len, specs, value);
	else
		fill_unsigned(perc_len, specs, value);
}
