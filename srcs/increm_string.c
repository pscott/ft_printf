/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increm_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:05:05 by pscott            #+#    #+#             */
/*   Updated: 2018/12/19 16:10:24 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	increm_string(char **s1, int len, t_arg *specs)
{
	if (s1 && *s1)
	{
		*s1 += len;
		specs->this_len += len;
	}
}
