/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:47:31 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 18:54:42 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_data_len(t_arg *specs, LL value)
{
	if (specs->type == 'd' || specs->type == 'i')
		value_d(specs, value);
	else if (specs->type == 'x')
		value_x(specs, value);
	else if (specs->type == 'X')
		value_xx(specs, value);
	else if (specs->type == 'o')
		value_o(specs, value);
	else if (specs->type == 'c')
		specs->data_len = 1;
	else if (specs->type == 's')
		specs->data_len = ft_strlen((char *)value);
	else if (specs->type == 'u')
		value_u(specs, value);
}
