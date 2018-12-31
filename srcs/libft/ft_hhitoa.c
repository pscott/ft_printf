/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:16:04 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 18:17:50 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_hhlen(signed char n)
{
	int len;

	len = 0;
	if (n == -128)
		return (3);
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static void	fill_itoa(signed char n, char *src, int len)
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

	str = "128";
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char		*ft_hhitoa(signed char n)
{
	char	*res;
	int		len;

	len = get_hhlen(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (n == -128)
		return (int_min(res));
	if (n < 0)
		n = -n;
	fill_itoa(n, res, len);
	return (res);
}
