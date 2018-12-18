/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:00:24 by pscott            #+#    #+#             */
/*   Updated: 2018/12/18 11:54:45 by pscott           ###   ########.fr       */
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

void	check_conv_value(t_arg *specs, char *value)
{
	if (*value == '0' && specs->precision && specs->precision_len == 0)
		specs->data_len = 0;
}

void	put_ox(t_arg *specs, char *value, int *perc_len, int modif)
{
	if (specs->hash && value[0] != '0')
	{
		if (modif == 0 && specs->fill == '0')
		{
			*perc_len -= 2;
			ft_strncat_move(specs->string, ox_helper(specs), 2, specs);
		}
		else if (modif == 1 && specs->fill != '0')
			ft_strncat_move(specs->string, ox_helper(specs), 2, specs);
		else if (modif == 2)
		{
			if (specs->fill == '0')
				*perc_len -= 2;
			ft_strncat_move(specs->string, ox_helper(specs), 2, specs);
		}
	}
}

void	ft_strncat_move(char *dst, char *src, int n, t_arg *specs)
{
	ft_strncat(dst, src, n);
	specs->string += n;
}
