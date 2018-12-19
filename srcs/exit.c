/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:48:28 by pscott            #+#    #+#             */
/*   Updated: 2018/12/19 17:00:46 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_exit(char *message, t_arg *specs)
{
	if (specs)
	{
		if (specs->origin)
			free(specs->origin);
		free(specs);
	}
	if (message)
		ft_putstr(message);
	exit(1);
}
