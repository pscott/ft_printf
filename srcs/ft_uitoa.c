/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:57:00 by pscott            #+#    #+#             */
/*   Updated: 2018/12/16 12:29:34 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_len(unsigned long long n)
{
	int len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static void	fill_uitoa(unsigned long long n, char *src, int len)
{
	while (n > 9)
	{
		src[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	src[0] = n + '0';
}

char		*ft_uitoa(unsigned long long n)
{
	char	*res;
	int		len;

	len = get_len(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	fill_uitoa(n, res, len);
	return (res);
}
