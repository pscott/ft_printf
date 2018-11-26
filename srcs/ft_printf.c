/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 18:44:10 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//NEED RESTRICT ON PRINTF;
void	ft_printf(const char *format, ...)
{
	va_list	int_arg_pointer;
	t_arg	*specs;

	va_start(int_arg_pointer, format);
	if (!format)
		return ;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!(specs = create_specs((char **)&format)))
				return ;
			if (specs->perc)
				ft_putchar('%');
			else
				parse_struct(specs, va_arg(int_arg_pointer, int));
			free(specs);
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	va_end(int_arg_pointer);
}

int	main(void)
{
	ft_printf(":%+05d:\n", -13);
	   printf(":%+05d:\n", -13);
	return (0);
}

// need to create struct, put all info in it, then (maybe) use pointer funcions to print the struct with specs, then rince and repeat !
