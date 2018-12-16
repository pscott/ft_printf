/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:12:15 by pscott            #+#    #+#             */
/*   Updated: 2018/12/16 19:15:51 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ox_helper(t_arg *specs)
{
	char *one;

	if (specs->type == 'x' || specs->type == 'o')
	{
		one = "0x";
		return (one);
	}
	else if (specs->type == 'X' || specs->type == 'O')
	{
		one = "0X";
		return (one);
	}
	return (NULL);
}
