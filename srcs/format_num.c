/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:28:04 by pscott            #+#    #+#             */
/*   Updated: 2018/12/14 17:37:40 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_num(t_arg *specs, ULL value)
{
	if (specs->l == 2)
		format_llint(specs, value);
	else if (specs->l == 1)
		format_lint(specs, value);
	else
		format_int(specs, value);
}
