/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:42:16 by pscott            #+#    #+#             */
/*   Updated: 2018/12/18 13:30:04 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_move(char **str, t_arg *specs)
{
	int		finalnb;

	finalnb = 0;
	while (ft_isdigit(**str))
	{
		finalnb = finalnb * 10 + **str - '0';
		increm_string(str, NULL, 1, specs);
	}
	return (finalnb);
}
