/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:28:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 17:10:54 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ULL i;
	char *str;
	char *c;

	str = ":%12-24-2s:\n";
	i = (unsigned long long int)2147483647;
	c = "azerty";

	ft_printf(str, c);
	printf(str, c);
}
