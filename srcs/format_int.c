/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:21:39 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 13:37:52 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:11:35 by pscott            #+#    #+#             */
/*   Updated: 2018/11/30 12:21:36 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_blanks_left(int perc_len, t_arg *specs, LL value)
{
	char	sign;
	char	*nb;

	sign = value >= 0 ? '+' : '-';
	if (specs->plus || value < 0)
	{
		printf("ah\n");
		*specs->string = sign;
		specs->string++;
		specs->nb_len--;
		perc_len--;
	}
	nb = ft_itoa_spec(specs, value);
	ft_strcat(specs->string, nb);
	specs->string += specs->nb_len;
	while (specs->nb_len < perc_len)
	{
		*specs->string = ' ';
		perc_len--;
		specs->string++;
	}
	free(nb);
}

int		sign_len(t_arg *specs, LL value)
{
	if (specs->plus)
		return (1);
	if (value < 0)
		return (1);
	return (0);
}

void	fill_blanks(int perc_len, t_arg *specs, LL value)
{
	char	sign;
	char	*nb;

	sign = value >= 0 ? '+' : '-';
	if (specs->fill == '0')
	{
		if (specs->plus || value < 0)
		{
			*specs->string = sign;
			specs->string++;
		}
	}
	while (specs->nb_len < perc_len)
	{
		*specs->string = specs->fill;
		perc_len--;
		specs->string++;
	}
	if (specs->fill == ' ')
	{
		if (specs->plus || value < 0)
		{
			*specs->string = sign;
			specs->string++;
		}
	}
	nb = ft_itoa_spec(specs, value);
	ft_strcat(specs->string, nb);
	specs->string += specs->nb_len - sign_len(specs, value);
	free(nb);
}

void	set_nb_len(t_arg *specs, LL value)
{
	if (specs->l == 2)
		specs->nb_len = get_lllen((LL) value);
	else if (specs->l == 1)
		specs->nb_len = get_llen((L) value);
	else if (specs->l == 0)
		specs->nb_len = get_len((int) value);
}

void	format_int(t_arg *specs, LL value)
{
	int		 perc_len;

	set_nb_len(specs, value);
	perc_len = max(specs->nb_len, specs->width);
	if (specs->plus && value >= 0)
		specs->nb_len++;
	if (specs->left && specs->plus)
		specs->fill = ' ';
	if (specs->left)
		fill_blanks_left(perc_len, specs, value);
	else
		fill_blanks(perc_len, specs, value);
}
