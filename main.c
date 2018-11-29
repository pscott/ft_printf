/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:07:23 by pscott            #+#    #+#             */
/*   Updated: 2018/11/29 17:07:47 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
