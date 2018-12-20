/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 11:31:46 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 12:19:02 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:40:22 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 11:30:54 by pscott           ###   ########.fr       */
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

char	*ft_uitoa_spec(t_arg *specs, ULL value)
{
	char *res;

	if (specs->l == 2)
		res = ft_uitoa((ULL)value);
	else if (specs->l == 1)
		res = ft_uitoa((UL)value);
	else if (specs->h == 2)
		res = ft_uitoa((unsigned char)value);
	else if (specs->h == 1)
		res = ft_uitoa((unsigned short int)value);
	else
		res = ft_uitoa((unsigned int)value);
	return (res);
}

char	*ft_itoa_spec(t_arg *specs, LL value)
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

int		print_perc(t_arg *specs)
{
	if (!specs->fill)
		specs->fill = ' ';
	specs->data_len = 1;
	if (specs->type == '%')
		format_char(specs, '%');
	return (0);
}
int		handle_perc(char **format, t_arg *specs)
{
	increm_string(format, 1, specs);
	init_specs(specs);
	get_flags(format, specs);
	//get_extra(format, specs);
	(*format)++;
	if (specs->type == '%')
		return (print_perc(specs));
	return (1);
}

void	set_data_len(t_arg *specs, LL value)
{
	if (specs->type == 'd' || specs->type == 'i')
	{
		if (specs->l == 2)
			specs->data_len = get_lllen((LL) value);
		else if (specs->l == 1)
			specs->data_len = get_llen((L) value);
		else if (specs->h == 2)
			specs->data_len = get_len((signed char) value);
		else if (specs->h == 1)
			specs->data_len = get_len((short int) value);
		else
			specs->data_len = get_len((int) value);
	}
	else if (specs->type == 'x')
	{
		if (specs->l == 2)
			specs->conv_val = convert((ULL) value, 16, BASE_16_low);
		else if (specs->l == 1)
			specs->conv_val = convert((UL) value, 16, BASE_16_low);
		else if (specs->h == 2)
			specs->conv_val = convert((unsigned char) value, 16, BASE_16_low);
		else if (specs->h == 1)
			specs->conv_val = convert((short unsigned int) value, 16, BASE_16_low);
		else
			specs->conv_val = convert((unsigned int) value, 16, BASE_16_low);
		specs->data_len = ft_strlen(specs->conv_val);
	}
	else if (specs->type == 'X')
	{
		if (specs->l == 2)
			specs->conv_val = convert((ULL) value, 16, BASE_16_up);
		else if (specs->l == 1)
			specs->conv_val = convert((UL) value, 16, BASE_16_up);
		else if (specs->h == 2)
			specs->conv_val = convert((unsigned char) value, 16, BASE_16_up);
		else if (specs->h == 1)
			specs->conv_val = convert((short unsigned int) value, 16, BASE_16_up);
		else
			specs->conv_val = convert((unsigned int) value, 16, BASE_16_up);
		specs->data_len = ft_strlen(specs->conv_val);
	}
	else if (specs->type == 'o')
	{
		if (specs->l == 2)
			specs->conv_val = convert((ULL) value, 8, BASE_8);
		else if (specs->l == 1)
			specs->conv_val = convert((UL) value, 8, BASE_8);
		else if (specs->h == 2)
			specs->conv_val = convert((unsigned char) value, 8, BASE_8);
		else if (specs->h == 1)
			specs->conv_val = convert((short unsigned int) value, 8, BASE_8);
		else
			specs->conv_val = convert((unsigned int) value, 8, BASE_8);
		specs->data_len = ft_strlen(specs->conv_val);
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
		else if (specs->h == 2)
			specs->data_len = get_ulen((unsigned char) value);
		else if (specs->h == 1)
			specs->data_len = get_ulen((unsigned short int) value);
		else
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
	if (!specs->fill)
		specs->fill = ' ';
	set_data_len(specs, value);
	if (specs->type == 'c')
		format_char(specs, (char) value);
	/*tous les differents types*/
	/*realloc si necessaire*/
	else if (specs->type == 'u')
		format_unsigned(specs, (ULL) value);
	else if (specs->type == 'd' || specs->type == 'i')
		format_num(specs, value);
	else if (specs->type == 'x' || specs->type == 'X')
		format_conv(specs, specs->conv_val);
	else if (specs->type == 'o')
		format_conv(specs, specs->conv_val);
	else if (specs->type == 's')
		format_string(specs, (char *) value);
	else
		return (invalid_type());
	return (1);
}
