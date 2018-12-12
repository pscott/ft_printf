/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:14:25 by pscott            #+#    #+#             */
/*   Updated: 2018/12/12 17:37:09 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_specs(t_arg *specs)
{
	specs->type = 0;
	specs->width = 0;
	specs->width_len = 0;
	specs->precision = 0;
	specs->precision_len= 0;
	specs->fill = 0;
	specs->fill_len = 0;
	specs->left = 0;
	specs->plus = 0;
	specs->hash = 0;
	specs->l = 0;
	specs->h = 0;
	specs->u = 0;
	specs->data_len = 0;
	specs->error = 0;
	specs->extra= 0;
}

t_arg	*create_specs(t_arg *specs)
{
	if (!(specs = (t_arg *)malloc(sizeof(t_arg)))\
			|| !(specs->string = ft_strnew(100)))
		return (NULL);
	init_specs(specs);
	specs->origin = specs->string;
	return (specs);
}
