/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:28:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/29 19:24:33 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ULL i;
	char *str;

	str = ":%d\n:";
	i = 125;
	i = (int)i;

	ft_printf(str, i);
	   printf(str, i);
}