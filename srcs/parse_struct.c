/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:40:22 by pscott            #+#    #+#             */
/*   Updated: 2018/11/28 18:20:19 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_itoa(t_arg *specs, ULL value)
{
	char *res;

	if (specs->l == 2)
		res = ft_uitoa((ULL)value);
	else if (specs->l == 1)
		res = ft_uitoa((UL)value);
	else if (specs->h == 2)
		res = ft_uitoa((signed char)value);
	else if (specs->h == 1)
		res = ft_uitoa((unsigned short int)value);
	else
		res = ft_uitoa((unsigned int)value);
	return (res);
}

char	*ft_itoa_spec(t_arg *specs, long long int value)
{
	char *res;

	if (specs->l == 2)
		res = ft_itoa((LL)value);
	else if (specs->l == 1)
		res = ft_itoa((L)value);
	else if (specs->h == 2)
		res = ft_itoa((signed char)value);
	else if (specs->h == 1)
		res = ft_itoa((short int)value);
	else
		res = ft_itoa((int)value);
	return (res);
}

void	parse_struct(t_arg *specs, unsigned long long int value)
{
	char *tmp;

	/*why 50?? ==> len max(width, actual_len)*/
	if (specs->type == 'u')
		tmp = ft_itoa_spec(specs, (ULL)value);
	if (specs->type == 'd' || specs->type == 'i')
	{
		format_int(specs, (LL)value);
		tmp = ft_itoa_spec(specs, (LL)value);
	}
	ft_strcat(specs->string, tmp);
	ft_putstr(tmp);
	free(tmp);
	free(specs->string);
}
