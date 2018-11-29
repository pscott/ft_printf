/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/29 14:49:38 by pscott           ###   ########.fr       */
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

int	main(void)
{
	unsigned char c;
	ULL i;
	char *str;

	c = 'A';
	i = -12;
	i = (int)i;

	str = ":%+###005d:\n";
	ft_printf(str, i, i + 3);
	   printf(str, i , i + 3);
	return (0);
}

/* plutot que de ft_putchar, il faut compter la taille de la string une fois. Donc nb extra char + max(width, value) pour chaque value.*/
/* need to create struct, put all info in it, then (maybe) use pointer funcions to print the struct with specs, then rince and repeat !*/
/*A partir de la struct, calculer la len (max width, len). 
 * Si +, - et value >= 0: len +=1, padding avec 'space'
 * Si +, -, value < 0: len, padding avec 'space'
 * Si +, value > 0, len += 1
 * Si +, value < 0: len.
 * Si -, padding gauche, peu importe
 *
 * Il faut gerer le re-alloc
 */
