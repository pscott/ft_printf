/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:40:22 by pscott            #+#    #+#             */
/*   Updated: 2018/11/27 20:05:08 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_spec(t_arg *specs, long long int value, size_t *len)
{
	char *res;
	if (specs->ll)
		res = ft_itoa((long int)value);
	else if (specs->l)
		res = ft_itoa((long long int)value);
	else if (specs->hh)
		res = ft_itoa((signed char)value);
	else if (specs->h)
		res = ft_itoa((short int)value);
	else
		res = ft_itoa((int)value);
	*len = ft_strlen(res);
	return (res);
}

void	parse_struct(t_arg *specs, long long int value)
{
	char *res;
	size_t len;

	/*why 50?? ==> len max(width, actual_len)*/
	len = 0;
	value = (long long int)value;
	res = ft_strnew(50);
	if (specs->type == 'd')
	{
		res = ft_itoa_spec(specs, value, &len);
	}
	ft_putstr(res);
}
