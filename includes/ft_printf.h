/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:47:14 by pscott            #+#    #+#             */
/*   Updated: 2018/11/26 18:31:16 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// stdio
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_arg
{
	char	type;
	int		width;
	int		precision;
	char	fill;
	int		left;
	int		plus;
	int		hash;
	int		perc;
}					t_arg;

t_arg		*create_specs(char **format);
void		parse_struct(t_arg *specs, int value);
void		print_int(t_arg *specs, int value);
int			ft_atoi_move(char **src);
void		print_spec(t_arg *specs);
int			get_len(int value);
int			print_int_minus(t_arg *specs, int value, int len, int width);
void		clean_exit(char *str, t_arg *specs);
#endif
