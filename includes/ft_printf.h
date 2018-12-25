/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:06:52 by pscott            #+#    #+#             */
/*   Updated: 2018/12/21 19:12:41 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# define ULL unsigned long long int
# define UL unsigned long int
# define LL long long int
# define L long int
# define BASE_8 "012345678"
# define BASE_16_LOW "0123456789abcdef"
# define BASE_16_UP "0123456789ABCDEF"

typedef struct	s_arg
{
	char		type;
	int			width;
	int			width_len;
	int			precision;
	int			precision_len;
	char		fill;
	int			fill_len;
	int			left;
	int			plus;
	int			hash;
	int			l;
	int			h;
	int			data_len;
	char		*conv_val;
	char		*string;
	char		*origin;
	int			mall_len;
	int			extra;
}				t_arg;

char			*convert(ULL num, int base, char *rep);
char			*convert_p(L num, int base, char *rep);
int				ft_printf(const char *format, ...);
int				parse_struct(t_arg *specs, ULL value);
char			*ft_itoa_spec(t_arg *specs, LL value);
int				handle_perc(char **fornat, t_arg *specs);
int				print_perc(t_arg *specs, char **value);
char			*unsigned_itoa(t_arg *specs, ULL value);
char			*ft_uitoa_spec(t_arg *specs, ULL value);
void			init_specs(t_arg *specs);
void			reset_specs(t_arg *specs);
t_arg			*create_specs(t_arg *specs);
void			malloc_string(t_arg *specs, int len);
void			realloc_if_necessary(t_arg *specs, int len);
int				valid_flags(char **format);
int				is_valid_type(char c);
int				min(int a, int b);
int				max(int a, int b);
void			set_extra(char c, t_arg *specs);
void			init_specs(t_arg *specs);
t_arg			*create_specs(t_arg *specs);
int				get_ulllen(ULL value);
int				get_ullen(UL value);
int				get_ulen(unsigned int value);
int				get_lllen(LL value);
int				get_llen(L value);
int				get_len(int value);
int				get_flags(char **format, t_arg *specs);
int				is_type(char **format, t_arg *specs);
int				is_spec_upper(char c);
void			get_preci(char **format, t_arg *specs);
void			get_extra(char **format, t_arg *specs);
void			format_int(t_arg *specs, int value);
void			format_lint(t_arg *specs, L value);
int				sign_llen(t_arg *spec, L value);
void			format_llint(t_arg *specs, LL value);
int				sign_lllen(t_arg *spec, LL value);
void			format_unsigned(t_arg *specs, ULL value);
void			format_p(t_arg *specs, L value);
int				unsigned_len(t_arg *spec, ULL value);
void			format_num(t_arg *specs, ULL value);
void			format_char(t_arg *specs, char *value);
void			fill_char(int perc_len, t_arg *specs, char *value);
void			fill_char_left(int perc_len, t_arg *specs, char *value);
void			format_string(t_arg *specs, char *value);
void			format_conv(t_arg *specs, char *value);
char			*ft_hitoa(short int n);
char			*ft_hhitoa(short int n);
int				ft_atoi_move(char **src);
int				null_data(t_arg *specs, ULL value);
int				isprint_special(char c);
void			get_preci_flags(char **format, t_arg *specs);
void			ft_strncat_move(char *src, int n, t_arg *specs);
void			put_ox(t_arg *specs, char *value, int *perc_len, int modif);
void			put_px(t_arg *specs, L value, int *perc_len);
void			check_conv_value(t_arg *specs, char *value);
int				ox_len(t_arg *specs);
void			ft_special_memset(t_arg *specs, char c, int len);
void			increm_string(t_arg *specs, int len);
void			increm_format(char **s1, int len);
void			set_data_len(t_arg *specs, LL value);
void			value_d(t_arg *specs, LL value);
void			value_x(t_arg *specs, LL value);
void			value_xx(t_arg *specs, LL value);
void			value_o(t_arg *specs, LL value);
void			value_u(t_arg *specs, LL value);
#endif
