/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:39:55 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 18:43:23 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		valid_info(char **format)
{
	if (**format == '-' || **format == '+' || **format == '#' \
			|| **format == '#' || **format == '%')
		return (1);
	return (0);
}

void	get_info(char **format, t_arg *specs)
{
	specs->left = 0;
	specs->plus = 0;
	specs->perc = 0;
	specs->hash = 0;
	while (valid_info(format))
	{
		if (**format == '-')
			specs->left = 1;
		else if (**format == '+')
			specs->plus = 1;
		else if (**format == '#')
			specs->hash= 1;
		else if (**format == '%')
			specs->perc = 1;
		(*format)++;
	}
}

void	get_fill(char **format, t_arg *specs)
{
	get_info(format, specs);
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
	return (len == 0 ? 1 : len);
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
	printf("\nType: %c\tWidth: %d\tPrecision: %d\tFill: %c\tLeft: %i\tPlus: %i\tHash: %i\tPerc: %i\n", specs->type, specs->width, specs->precision, specs->fill, specs->left, specs->plus, specs->hash, specs->perc);
	return ;
}

t_arg	*create_specs(char **format)
{
	t_arg	*specs;

	if (!(specs = (t_arg *)malloc(sizeof(t_arg))))
		clean_exit(NULL, specs);
	get_fill(format, specs);
	//print_spec(specs);
	if (specs->perc)
		return (specs);
	specs->width = ft_atoi_move(format);
	specs->precision = 0;
	get_type(format, specs);
	//print_spec(specs);
	return (specs);
	/*
	   get_precision(format, specs);
	   get_type(format, specs);*/
}
