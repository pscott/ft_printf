/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:14:25 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 19:17:27 by pscott           ###   ########.fr       */
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
	specs->total_len = 0;
	specs->data_len = 0;
	specs->error = 0;
	specs->mall_len = 0;
	specs->extra= 0;
}

void	malloc_string(t_arg *specs, int len)
{
	char	*tmp;

	if (!(specs->string))
	{
		if (!(specs->string = ft_strnew(len)))
			return ;
		specs->origin = specs->string;
		specs->mall_len = len;
	}
	else
	{
		if (!(tmp = ft_strnew(len)))
			return ;
		ft_strcpy(tmp, specs->origin);
		free(specs->origin);
		specs->string = tmp;
		specs->origin = tmp;
		specs->string += specs->mall_len;
	}
}

t_arg	*create_specs(t_arg *specs)
{
	if (!(specs = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	malloc_string(specs, 1);
	init_specs(specs);
	return (specs);
}
