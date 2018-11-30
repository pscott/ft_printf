/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:11:03 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 17:10:49 by pscott           ###   ########.fr       */
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
			specs->fill = '0';
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
	ft_putchar(specs->type);
	get_lh(format, specs);
	ft_putchar(specs->type);
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
