/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:11:03 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 17:28:37 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(char **format, t_arg *specs)
{
	char	c;
	int		val;

	if (!**format)
		specs->type = '1';
	while (isprint_special(**format))
	{
		c = **format;
		if (c == '.')
		{
			increm_string(format, 1, specs);
			specs->precision = 1;
			specs->fill = ' ';
			specs->precision_len = ft_atoi_move(format);
		}
		if ((val = is_type(format, specs)))
		{
			specs->type = **format;
			return (val);
		}
		if (c == '-')
			specs->left += 1;
		else if (c == '+')
			specs->plus += 1;
		else if (c == '#')
			specs->hash += 1;
		else if (c == '0' && specs->fill != ' ')
			specs->fill = '0';
		else if (c == ' ')
		{
			set_extra(c, specs);
			specs->fill = ' ';
		}
		else if (ft_isdigit(c))
		{
			if ((specs->width_len = ft_atoi_move(format)))
			{
				specs->width = 1;
				increm_string(format, -1, specs);
			}
		}
		increm_string(format, 1, specs);
	}
	return (0);
}

void	get_lh(char **format, t_arg *specs)
{
	int i;

	i = 0;
	while ((*format)[i] == 'h' || (*format)[i]  == 'l')
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
	if (specs->h > 2)
		specs->h = 2;
	if (specs->l > 2)
		specs->l = 2;
}

int		is_spec_upper(char c)
{
	if (c >= 'A' && c <= 'Z' && c != 'X' && c != 'F')
		return (1);
	return (0);
}

int		is_type(char **format, t_arg *specs)
{
	char c;

	get_lh(format, specs);
	c = **format;
	if (is_valid_type(c))
	{
		specs->type = c;
		return (1);
	}
	return (0);
}
