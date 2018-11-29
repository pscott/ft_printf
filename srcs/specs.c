/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:39:55 by pscott            #+#    #+#             */
/*   Updated: 2018/11/29 10:35:43 by pscott           ###   ########.fr       */
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

int		get_len(LL value)
{
	int len;

	len = 0;
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

int		max(int a, int b)
{
	return (a < b ? b : a);
}

void	set_lh(char **format, t_arg *specs)
{
	int i;

	i = 0;
	if (**format == 'u')
	{
		specs->u = 1;
		(*format)++;
	}
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

int		is_valid_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'i' || c == 'x' \
			|| c == 'X' || c == 'u')
		return (1);
	return (0);
}

void	get_type(char **format, t_arg *specs)
{
	set_lh(format, specs);
	/*gerer les cas d'erreur pls */
	if (!is_valid_type(**format))
		specs->error = 1;
	specs->type = **format;
	(*format)++;
}

void	init_specs(t_arg *specs)
{
	specs->type = 0;
	specs->width = 0;
	specs->precision = 0;
	specs->fill = 0;
	specs->left = 0;
	specs->plus = 0;
	specs->hash = 0;
	specs->perc = 0;
	specs->l = 0;
	specs->h = 0;
	specs->u = 0;
	specs->origin = specs->string;
	specs->error = 0;
}

void	print_spec(t_arg *specs)
{
	printf("\nType: %c\tWidth: %d\tPrecision: %d\tFill: %c\tLeft: %i\tPlus: %i\tHash: %i\tPerc: %i\n", specs->type, specs->width, specs->precision, specs->fill, specs->left, specs->plus, specs->hash, specs->perc);
	return ;
}

t_arg	*create_specs(char **format, t_arg *specs)
{
	if (!specs)
	{
		if (!(specs = (t_arg *)malloc(sizeof(t_arg)))\
				|| !(specs->string = ft_strnew(100)))
			return (NULL);
	}
	init_specs(specs);
	get_fill(format, specs);
	//print_spec(specs);
	if (specs->perc)
		return (specs);
	specs->width = ft_atoi_move(format);
	get_type(format, specs);
	//print_spec(specs);
	return (specs);
	/*
	   get_precision(format, specs);
	   get_type(format, specs);*/
}
