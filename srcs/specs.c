/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:39:55 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 14:24:08 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_fill(char **format, t_arg *specs)
{
	specs->fill = ' ';
	if (**format == '0')
	{
		specs->fill = '0';
		(*format)++;
	}
	else if (**format == ' ')
		(*format)++;
}

int		get_len(int value)
{
	int len;

	len = 0;
	if (value == -2147483648)
		return (11);
	if (value < 0)
	{
		len++;
		value = -value;
	}
	while (value > 0)
	{
		len++;
		value /= 10;
	}
	return (len);
}

void	parse_struct(t_arg *specs, int value)
{
	if (specs->type == 'd')
		print_int(specs, value);
	else
		ft_putstr("not int");
	return ;
}

void	get_type(char **format, t_arg *specs)
{
	specs->type = **format;
	(*format)++;
}

void	print_spec(t_arg *specs)
{
	printf("Type: %c\tWidth: %d\tPrecision: %d\tFill: %c\n", specs->type, specs->width, specs->precision, specs->fill);
	return ;
}

t_arg	*create_specs(char **format)
{
	t_arg	*specs;

	if (!(specs = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	get_fill(format, specs);
	specs->width = ft_atoi_move(format);
	specs->precision = 0;
	get_type(format, specs);
	//print_spec(specs);
	return (specs);
	/*
	   get_precision(format, specs);
	   get_type(format, specs);*/
}
