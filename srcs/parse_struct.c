/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:40:22 by pscott            #+#    #+#             */
/*   Updated: 2018/12/15 17:17:09 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_itoa(t_arg *specs, ULL value)
{
	char *res;

	if (specs->l == 2)
		res = ft_uitoa((ULL)value);
	else if (specs->l == 1)
		res = ft_uitoa((UL)value);
	else if (specs->h == 2)
		res = ft_uitoa((signed char)value);
	else if (specs->h == 1)
		res = ft_uitoa((unsigned short int)value);
	else
		res = ft_uitoa((unsigned int)value);
	return (res);
}

char	*ft_itoa_spec(t_arg *specs, long long int value)
{
	char *res;

	if (specs->l == 2)
		res = ft_llitoa((LL)value);
	else if (specs->l == 1)
		res = ft_litoa((L)value);
	else if (specs->h == 2)
		res = ft_hhitoa((signed char)value);
	else if (specs->h == 1)
		res = ft_hitoa((short int)value);
	else
		res = ft_itoa((int)value);
	return (res);
}

int		handle_perc(char **format, t_arg *specs, ULL value)
{
	(*format)++;
	init_specs(specs);
	get_flags(format, specs);
	specs->width_len = ft_atoi_move(format);
	if (specs->width_len > 0)
		specs->width = 1;
	get_preci(format, specs);
	get_extra(format, specs);
	get_type(format, specs);
	set_data_len(specs, value);
	if (!specs->fill)
		specs->fill = ' ';
	return (parse_struct(specs, value));
}

int		sum_struct(t_arg *specs)
{
	int res;

	res = specs->type ? 1 : 0;
	res += specs->width_len + specs->precision_len + specs->fill_len \
		   + specs->left + specs->plus + specs->hash + specs->l + specs->h \
		   + specs->u;
	return (res);
}

void	set_data_len(t_arg *specs, LL value)
{
	if (specs->type == 'd' || specs->type == 'i')
	{
		if (specs->l == 2)
			specs->data_len = get_lllen((LL) value);
		else if (specs->l == 1)
			specs->data_len = get_llen((L) value);
		else if (specs->l == 0)
			specs->data_len = get_len((int) value);
	}
	else if (specs->type == 'c')
		specs->data_len = 1;
	else if (specs->type == 's')
		specs->data_len = ft_strlen((char *)value);
	else if (specs->type == 'u')
	{
		if (specs->l == 2)
			specs->data_len = get_ulllen((ULL) value);
		else if (specs->l == 1)
			specs->data_len = get_ullen((UL) value);
		else if (specs->l == 0)
			specs->data_len = get_ulen((unsigned int) value);
	}
}

int		invalid_type(void)
{
	/*TODO: think about what happens when types are invalid*/
	return (-1);
}

int		parse_struct(t_arg *specs, ULL value)
{
	if (specs->type == '%')
		format_char(specs, '%');
	else if (specs->type == 'c')
		format_char(specs, (char) value);
	/*tous les differents types*/
	/*realloc si necessaire*/
	/*why 100?? ==> len max(width, actual_len)*/
	/*if (specs->type == 'u')
		tmp = ft_itoa_spec(specs, (ULL)value);*/
	else if (specs->type == 'u')
		format_unsigned(specs, (ULL) value);
	else if (specs->type == 'd' || specs->type == 'i')
		format_num(specs, value);
	else if (specs->type == 's')
		format_string(specs, (char *) value);
	else
		return (invalid_type());
	return (sum_struct(specs));
}
