/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increm_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:39:01 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 19:15:36 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	increm_string(t_arg *specs, int len)
{
	if (specs->total_len + len <= specs->mall_len - 1)
		specs->string += len;
	else
	{
		malloc_string(specs, specs->mall_len * 2);
		specs->string++;
	}
}
