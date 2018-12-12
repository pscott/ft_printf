/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:11:03 by pscott            #+#    #+#             */
/*   Updated: 2018/12/12 17:54:12 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(char **format, t_arg *specs)
{
	char c;

	while (valid_flags(format))
	{
		c = **format;
		if (c == '-')
			specs->left += 1;
		else if (c == '+')
			specs->plus += 1;
		else if (c == '#')
			specs->hash += 1;
		else if (c == '0')
		{
			if (specs->fill == ' ')
				specs->extra = 1;
			specs->fill = '0';
		}
		else if (c == ' ')
		{
			if (specs->fill == '0')
				specs->extra = 1;
			else
				specs->fill = ' ';
		}
		if (c == '0' || c == ' ')
			specs->fill_len += 1;
		(*format)++;
	}
}

void	get_lh(char **format, t_arg *specs)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if ((*format)[i] == 'h')
			specs->h++;
		else if ((*format)[i] == 'l')
			specs->l++;
		i++;
	}
	/* gerer les cas d'erreur pls */
	if (specs->h && specs->l)
		specs->error = 1;
	(*format) = (*format) + max(specs->h, specs->l) + specs->u;
}

void	get_type(char **format, t_arg *specs)
{
	get_lh(format, specs);
	/*gerer les cas d'erreur pls */
	if (!is_valid_type(**format))
		specs->error = 1;
	specs->type = **format;
	(*format)++;
}

void	get_preci(char **format, t_arg *specs)
{
	if (**format == '.')
	{
		(*format)++;
		specs->precision = 1;
		if (ft_isdigit(**format))
			specs->precision_len = ft_atoi_move(format);
	}
}

void	get_extra(char **format, t_arg *specs)
{
	if (**format == ' ')
	{
		(*format)++;
		if (specs->fill != 0)
			specs->extra = 1;
	}
}
