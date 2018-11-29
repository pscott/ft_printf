/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/29 20:42:01 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	int_arg_pointer;
	t_arg	*specs;
	int		total_len;

	specs = NULL;
	va_start(int_arg_pointer, format);
	if (!format)
		return (-1);
	if (!(specs = create_specs((char **)&format, specs)))
		return (-1);
	while (*format)
	{
		if (*format == '%')
			format = format + parse_struct(specs, va_arg(int_arg_pointer, ULL));
		else
		{
			*(specs->string) = *format;
			format++;
			specs->total_len++;
		}
	}
	va_end(int_arg_pointer);
	total_len = ft_strlen(specs->origin);
	write(1, specs->origin, total_len);
	printf("\nAddress: %p\n", specs->origin);
	free(specs->origin);
	free(specs);
	/* return value not good*/
	return (total_len);
}
