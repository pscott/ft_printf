/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:11:03 by pscott            #+#    #+#             */
/*   Updated: 2018/12/18 17:57:38 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(char **format, t_arg *specs)
{
	char c;

	while (**format)
	{
		if (is_type(format, specs, 0) == 1)
			return (1);
		if (is_type(format, specs, 0) == 2)
			return (2);
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
		//???
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
	return (0);
}

void	get_lh(char **format, t_arg *specs)
{
	int i;

	i = 0;
	while (**format == 'h' || **format  == 'l')
	{
		if (**format == 'h')
			specs->h++;
		else if (**format == 'l')
			specs->l++;
		i++;
		(*format)++;
	}
	/* gerer les cas d'erreur pls */
	if (specs->h && specs->l)
		specs->error = 1;
	if (specs->h > 2)
		specs->h = 2;
	if (specs->l > 2)
		specs->l = 2;
	(*format) += i;
}

int		is_type(char **format, t_arg *specs, int modif)
{
	char c;

	c = **format;
	get_lh(format, specs);
	if (modif == 0 && c == '.')
		return (2);
	if (c == 'i' || c == 'd' || c == 'p' ||
			c == 'f' || c == 'x' || c == 'X' || c == 'o' || c == 's' || c == 'c')
	{
		specs->type = **format;
		printf("FORMAT ICI: %c\n", **format);
		/*gerer les cas d'erreur pls */
		return (1);
	}
	return (0);
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
		if (specs->fill != 0)
			set_extra(**format, specs);
		(*format)++;
	}
	set_extra(**format, specs);
}
