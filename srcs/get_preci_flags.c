/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_preci_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:19:08 by pscott            #+#    #+#             */
/*   Updated: 2018/12/18 17:48:22 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_preci_flags(char **format, t_arg *specs)
{
	char c;

	while (**format)
	{
		if (is_type(format, specs, 1))
			return ;
		c = **format;
		if (c == '-')
			specs->left += 1;
		else if (c == '+')
			specs->plus += 1;
		else if (c == '#')
			specs->hash += 1;
		else if (c == '0')
		{
			if (specs->fill != ' ')
				specs->fill = '0';
		}
		else if (c == ' ')
		{
			set_extra(c, specs);
			specs->fill = ' ';
		}
		//????
		else if (c == '0' || c == ' ')
			specs->fill_len += 1;
		else if (ft_isdigit(c))
		{
			specs->precision_len = ft_atoi_move(format);
			(*format)--;
		}
		(*format)++;
	}
}
