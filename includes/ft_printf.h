/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:47:14 by pscott            #+#    #+#             */
/*   Updated: 2018/12/20 11:04:38 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// stdio && gnl
# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h" 
# define ULL unsigned long long int
# define UL unsigned long int
# define LL long long int
# define L long int
# define BASE_8 "012345678"
# define BASE_16_low "0123456789abcdef"
# define BASE_16_up "0123456789ABCDEF"

typedef struct		s_arg
{
	char			type;
	int				width;
	int				width_len;
	int				precision;
	int				precision_len;
	char			fill;
	int				fill_len;
	int				left;
	int				plus;
	int				hash;
	int				l;
	int				h;
	int				this_len;
	int				data_len;
	char			*conv_val;
	char			*string;
	char			*tmp;
	char			*origin;
	int				error;
	int				mall_len;
	int				extra;
}					t_arg;

/* converters.c */
char	*convert(ULL num, int base, char *rep);

/* ft_printf */
int			ft_printf(const char *format, ...);

/* parse_struct.c */
int			parse_struct(t_arg *specs, ULL value);
void		set_data_len(t_arg *specs, LL value);
char		*ft_uitoa_spec(t_arg *specs, ULL value);
char		*ft_itoa_spec(t_arg *specs, LL value);
char		*unsigned_itoa(t_arg *specs, ULL value);
int			handle_perc(char **fornat, t_arg *specs);

/* spec_init.c */
void		init_specs(t_arg *specs);
t_arg		*create_specs(t_arg *specs);

/* utils.c */
int			valid_flags(char **format);
int			is_valid_type(char c);
int			min(int a, int b);
int			max(int a, int b);
void		set_extra(char c, t_arg *specs);

/* spec_init.c */
void		init_specs(t_arg *specs);
t_arg		*create_specs(t_arg *specs);

/* get_ulen.c */
int			get_ulllen(ULL value);
int			get_ullen(UL value);
int			get_ulen(unsigned int value);

/* get_len.c */
int			get_lllen(LL value);
int			get_llen(L value);
int			get_len(int value);

/*getters.c*/
int			get_flags(char **format, t_arg *specs);
int			is_type(char **format, t_arg *specs);
void		get_preci(char **format, t_arg *specs);
void		get_extra(char **format, t_arg *specs);

/* format_int.c */
void	format_int(t_arg *specs, int value);

/* format_lint.c */
void	format_lint(t_arg *specs, L value);
int		sign_llen(t_arg *spec, L value);

/* format_llint.c */
void	format_llint(t_arg *specs, LL value);
int		sign_lllen(t_arg *spec, LL value);

/* format_unsigned.c */
void		format_unsigned(t_arg *specs, ULL value);
int			unsigned_len(t_arg *spec, ULL value);

/* format_num.c */
void		format_num(t_arg *specs, ULL value);

/* format_char.c */
void		format_char(t_arg *specs, char value);
void		fill_char(int perc_len, t_arg *specs, char value);
void		fill_char_left(int perc_len, t_arg *specs, char value);

/* format_string.c */
void		format_string(t_arg *specs, char *value);

/* format_conv.c */
void		format_conv(t_arg *specs, char *value);

/* ft_hitoa.c */
char		*ft_hitoa(short int n);

/* ft_hhitoa.c */
char		*ft_hhitoa(short int n);

/* ft_atoi_move.c*/
int			ft_atoi_move(char **src);


char		*ft_strcat_free(char *s1, char *s2);

/* null_data.c */
int			null_data(t_arg *specs, ULL value);

/* get_preci_flags.c */
void		get_preci_flags(char **format, t_arg *specs);

/* conv_helper.c */
void		put_ox(t_arg *specs, char *value, int *perc_len, int modif);
void		check_conv_value(t_arg *specs, char *value);
void		ft_strncat_move(char *dst, char *src, int n, t_arg *specs);
int			ox_len(t_arg *specs);

/* increm_string.c */
void		increm_string(char **s1, int len, t_arg *specs);

#endif
