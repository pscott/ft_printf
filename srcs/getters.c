/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:11:03 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 18:41:27 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_if_flags(t_arg *specs, char c, char **format)
{
	if (c == '-')
		specs->left += 1;
	else if (c == '+')
		specs->plus += 1;
	else if (c == '#')
		specs->hash += 1;
	else if (c == '0')
		specs->fill = '0';
	else if (c == ' ')
	{
		set_extra(c, specs);
		if (specs->fill != '0')
			specs->fill = ' ';
	}
	else if (ft_isdigit(c))
	{
		if ((specs->width_len = ft_atoi_move(format)))
		{
			specs->width = 1;
			increm_format(format, -1);
		}
	}
	increm_format(format, 1);
}

int		get_flags(char **format, t_arg *specs)
{
	char	c;

	if (!**format)
		specs->type = '1';
	while (isprint_special(**format))
	{
		c = **format;
		if (c == '.')
		{
			increm_format(format, 1);
			specs->precision = 1;
			specs->fill = ' ';
			specs->precision_len = ft_atoi_move(format);
			(*format)--;
		}
		if (is_type(format, specs))
			return (specs->type = **format);
		if (is_spec_upper(**format))
			return (specs->type = '%');
		check_if_flags(specs, c, format);
	}
	return (0);
}

void	get_lh(char **format, t_arg *specs)
{
	int i;

	i = 0;
	while ((*format)[i] == 'h' || (*format)[i] == 'l')
	{
		if ((*format)[i] == 'h')
			specs->h++;
		else if ((*format)[i] == 'l')
			specs->l++;
		i++;
	}
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
