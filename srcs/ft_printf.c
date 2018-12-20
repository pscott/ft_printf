/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:34:09 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 19:13:05 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict f, ...)
{
	va_list	arg;
	t_arg	*specs;
	int		total_len;

	specs = NULL;
	va_start(arg, f);
	if (!f)
		return (-1);
	if (!(specs = create_specs(specs)))
		return (-1);
	while (*f)
	{
		if (*f == '%')
		{
			if (handle_perc((char **)&f, specs))
			{
				if (specs->type == '%')
					print_perc(specs, (char**)&f);
				else
					parse_struct(specs, va_arg(arg, ULL));
			}
			if (*f)
				f++;
		}
		else if (*f)
		{
			*(specs->string) = *f;
			f++;
			specs->string++;
		}
	}
	va_end(arg);
	total_len = specs->string - specs->origin;
	if (specs->origin)
	{
		write(1, specs->origin, total_len);
		free(specs->origin);
		free(specs);
	}
	return (total_len);
}
