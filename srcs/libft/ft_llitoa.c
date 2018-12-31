/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:46:44 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 19:00:21 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char		*ll_min(char *res)
{
	char				*str;
	long long int		i;

	str = "9223372036854775808";
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char		*ft_llitoa(long long int n)
{
	char	*res;
	int		len;

	len = get_lllen(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if ((unsigned long long int)n == -9223372036854775808U)
		return (ll_min(res));
	if (n < 0)
		n = -n;
	fill_itoa(n, res, len);
	return (res);
}
