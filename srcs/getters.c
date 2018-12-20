/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:11:03 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 12:20:42 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(char **format, t_arg *specs)
{
	char c;

	if (!**format)
		specs->type = '1';
	while (**format)
	{
		c = **format;
		if (c == '.')
		{
			increm_string(format, 1, specs);
			specs->precision = 1;
			specs->fill = ' ';
			specs->precision_len = ft_atoi_move(format);
		}
		if (is_type(format, specs))
			return (1);
		if (c == '-')
			specs->left += 1;
		else if (c == '+')
			specs->plus += 1;
		else if (c == '#')
			specs->hash += 1;
		else if (c == '0' && specs->fill != ' ')
			specs->fill = '0';
		else if (c == ' ')
		{
			set_extra(c, specs);
			specs->fill = ' ';
		}
		//???
		else if (c == '0' || c == ' ')
			specs->fill_len += 1;
		else if (ft_isdigit(c))
		{
			if ((specs->width_len = ft_atoi_move(format)))
			{
				specs->width = 1;
				increm_string(format, -1, specs);
			}
		}
		increm_string(format, 1, specs);
	}
	return (0);
}

void	get_lh(char **format, t_arg *specs)
{
	int i;

	i = 0;
	while (**format == 'h' || **format  == 'l')
	{
		if (**format == 'h')
			specs->h++;
		else if (**format == 'l')
			specs->l++;
		i++;
		increm_string(format, 1, specs);
	}
	/* gerer les cas d'erreur pls */
	if (specs->h && specs->l)
		specs->error = 1;
	if (specs->h > 2)
		specs->h = 2;
	if (specs->l > 2)
		specs->l = 2;
}

int		is_type(char **format, t_arg *specs)
{
	char c;

	get_lh(format, specs);
	c = **format;
	if (is_valid_type(c))
	{
		specs->type = c;
		/*gerer les cas d'erreur pls */
		return (1);
	}
	specs->type = '1';
	return (0);
}

/*void	get_extra(char **format, t_arg *specs)
  {
  while (**format == ' ')
  {
  if (specs->fill != 0)
  set_extra(**format, specs);
  (*format)++;
  }
  set_extra(**format, specs);
  }*/
