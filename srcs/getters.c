/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:11:03 by pscott            #+#    #+#             */
/*   Updated: 2018/12/15 20:40:14 by pscott           ###   ########.fr       */
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
			if (specs->fill != ' ')
				specs->fill = '0';
		}
		else if (c == ' ')
		{
			set_extra(c, specs);
			specs->fill = ' ';
		}
		else if (c == '0' || c == ' ')
			specs->fill_len += 1;
		else if (ft_isdigit(c))
		{
			if ((specs->width_len = ft_atoi_move(format)))
			{
				specs->width = 1;
				(*format)--;
			}
		}
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
		get_preci_flags(format, specs);
		specs->fill = ' ';
	}
}

void	get_extra(char **format, t_arg *specs)
{
	while (**format == ' ')
	{
		(*format)++;
		if (specs->fill != 0)
			set_extra(**format, specs);
	}
	set_extra(**format, specs);
}
