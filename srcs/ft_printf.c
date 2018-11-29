/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/29 17:37:35 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//NEED RESTRICT ON PRINTF;
int		ft_printf(const char *format, ...)
{
	va_list	int_arg_pointer;
	t_arg	*specs;

	specs = NULL;
	va_start(int_arg_pointer, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			/* if specs doesn't exist, create ; else do not create */
			if (!(specs = create_specs((char **)&format, specs)))
				return (-1);
			if (specs->perc)
				ft_putchar('%');
			else
				parse_struct(specs, va_arg(int_arg_pointer, ULL));
		}
		else
		{
			ft_putchar(*format);
			/* specs->srting++ */
			format++;
		}
	}
	va_end(int_arg_pointer);
	free(specs);
	/* return value not good*/
	return (1);
}
