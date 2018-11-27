/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:47:14 by pscott            #+#    #+#             */
/*   Updated: 2018/11/27 20:49:17 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// stdio && gnl
# include <stdio.h>
# include "get_next_line.h"

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_arg
{
	char			type;
	int				width;
	int				precision;
	char			fill;
	int				left;
	int				plus;
	int				hash;
	int				perc;
	int				l;
	int				ll;
	int				h;
	int				hh;
	char			*string;
	int				error;
}					t_arg;

/* ft_printf */

/* parse_struct.c */
void		parse_struct(t_arg *specs, long long int value);

/* specs.c */
t_arg		*create_specs(char **format);
int			get_len(int value);

/* printing.c */
void		print_spec(t_arg *specs);
void		print_int(t_arg *specs, int value);
int			print_int_left(t_arg *specs, int value, int len, int width);

/* misc */
void		clean_exit(char *str, t_arg *specs);
int			get_next_line(int fd, char **line);
int			ft_atoi_move(char **src);

#endif
