/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:50:48 by pscott            #+#    #+#             */
/*   Updated: 2018/11/29 16:56:33 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long long int n)
{
	int len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static void	fill_itoa(long long int n, char *src, int len)
{
	while (n > 9)
	{
		src[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	src[0] = n + '0';
}

char		*ft_itoa(long long int n)
{
	char	*res;
	int		len;

	len = get_len(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		n = -n;
	fill_itoa(n, res, len);
	return (res);
}