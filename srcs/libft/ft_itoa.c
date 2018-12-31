/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:50:48 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 18:59:58 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_itoa(int n, char *src, int len)
{
	while (n > 9)
	{
		src[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	src[0] = n + '0';
}

static char	*int_min(char *res)
{
	char	*str;
	int		i;

	str = "2147483648";
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = get_len(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (n == -2147483648)
		return (int_min(res));
	if (n < 0)
		n = -n;
	fill_itoa(n, res, len);
	return (res);
}
