/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/27 20:49:14 by pscott           ###   ########.fr       */
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
			/* if specs doesn't exist, create ; else do not create */
			if (!(specs = create_specs((char **)&format)))
				return ;
			if (specs->perc)
				ft_putchar('%');
			else
				parse_struct(specs, va_arg(int_arg_pointer, long long int));
			free(specs);
		}
		else
		{
			ft_putchar(*format);
			/* str_len++ */
			format++;
		}
	}
	va_end(int_arg_pointer);
}

int	main(void)
{
	unsigned char c;
	long long int i;
	char *str;

	c = 'A';
	i = 125;
	i = (int)i;

	printf("\n%lu\n", sizeof(i));
	str = ":%d:\n";
	ft_printf(str, i);
	   printf(str, i);
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
 */
