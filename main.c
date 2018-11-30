/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:28:09 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 13:37:53 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ULL i;
	char *str;

	str = ":%lld:\n";
	i = 124;
	i = (long long int)i;

	printf("%d\n", ft_printf(str, i));
	printf("%d\n", printf(str, i));
}
