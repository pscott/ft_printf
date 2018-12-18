/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increm_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:59:19 by pscott            #+#    #+#             */
/*   Updated: 2018/12/18 17:39:52 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		increm_string(char **s1, char *s2, int len, t_arg *specs)
{
	if (len)
	{
		if (s1 && *s1)
			*s1 += len;
		if (s2)
		{
			specs->string += len;
			specs->this_len++;
		}
		specs->total_len += len;
	}
	//if (total_len > specs->mall_len - 1) -> realloc
}
