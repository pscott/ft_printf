/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 13:16:18 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	addingNumbers(int nHowMany, ... )
{
	int	nSum = 0;

	va_list intArgumentPointer;
	int		i;

	va_start(intArgumentPointer, nHowMany);
	i = 0;
	while (i < nHowMany)
	{
		nSum += va_arg(intArgumentPointer, int);
		i++;
	}
	va_end(intArgumentPointer);

	return (nSum);
}

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
			if (!(specs = create_specs(format)))
				return ;
			parse_struct(specs, va_arg(int_arg_pointer, int));
			free(specs);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(int_arg_pointer);
}

int	main(void)
{
	/*printf("\n 10 + 20 = %d ", addingNumbers(2, 10, 20));*/
	ft_printf("%5d, %5d, %5d\n", -12, -13, 154);
	printf("%5d, %5d, %5d\n", -12, -13, 154);
	return (0);
}

// need to create struct, put all info in it, then (maybe) use pointer funcions to print the struct with specs, then rince and repeat !
