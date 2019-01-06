/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:40:22 by pscott            #+#    #+#             */
/*   Updated: 2019/01/06 19:32:08 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_spec(t_arg *specs, LL value)
{
	if (specs->l == 2)
		ft_llitoa(specs, (LL)value);
	else if (specs->l == 1)
		ft_litoa(specs, (L)value);
	else if (specs->h == 2)
		ft_hhitoa(specs, (signed char)value);
	else if (specs->h == 1)
		ft_hitoa(specs, (short int)value);
	else
		ft_itoa(specs, (int)value);
}

int		print_perc(t_arg *specs, va_list *arg)
{
	specs->type = 'c';
	parse_struct(specs, arg);
	return (1);
}

int		handle_perc(char **format, t_arg *specs, va_list *arg)
{
	increm_format(format, 1);
	reset_specs(specs);
	if (get_flags(specs, format, arg) == 2)
	{
		specs->type = '2';
		if (**format)
			(*format)++;
		return (3);
	}
	if (is_valid_type(specs->type))
		return (1);
	return (0);
}

int		parse_struct(t_arg *specs, va_list *arg)
{
	//printf("PRINT: %s\n", va_arg(*arg, char*));
	if (!specs->fill || (specs->precision && specs->type != 'c'
				&& specs->type != 's'))
		specs->fill = ' ';
//	set_data_len(specs, arg);
	if (specs->type == 'c')
		format_char(specs, va_arg(*arg, char*));
	else if (specs->type == 'u')
		format_unsigned(specs, va_arg(*arg, ULL));
	else if (specs->type == 'd' || specs->type == 'i')
		format_int(specs, va_arg(*arg, LL));
	else if (specs->type == 'o' || specs->type == 'x' || specs->type == 'X')
		format_conv(specs, va_arg(*arg, LL));
	else if (specs->type == 's')
		format_string(specs, va_arg(*arg, char*));
	else if (specs->type == 'p')
		format_p(specs, va_arg(*arg, L));
	return (1);
}
