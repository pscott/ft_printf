/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:42:32 by lroux             #+#    #+#             */
/*   Updated: 2018/11/30 17:54:26 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/*
** Part 0 - Macro & Types
*/

/*
**# if defined(__i386__)
**
**typedef signed char	t_int8;
**typedef unsigned char	t_uint8;
**
**typedef signed int	t_int16;
**typedef unsigned int	t_uint16;
**
**typedef signed long int	t_int32;
**typedef unsigned long int	t_uint32;
**
**typedef signed long long int	t_int64;
**typedef unsigned long long int	t_uint64;
**
**# elif defined(__x86_64__)
*/

typedef signed char	t_int8;
typedef unsigned char	t_uint8;

typedef signed short	t_int16;
typedef unsigned short	t_uint16;

typedef signed int	t_int32;
typedef unsigned int	t_uint32;

typedef signed long long int	t_int64;
typedef unsigned long long int	t_uint64;

/*
**# else
**#  error Unsupported architecture
**# endif
*/

/*
** Don't redefine bool if already defined
*/
# ifndef __STDBOOL_H

typedef enum {
	false = 0,
	true
}	t_bool;

# endif

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Part I - Memory operations
** Custom: ft_calloc, ft_realloc.
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(void *ptr, size_t size);

/*
** Part II - String/Char operations
** Custom: ft_strndup, ft_strnjoin, ft_strreset, ft_strjoinfree,
**  ft_strnjoinfree.
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *s1, const char *s2, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_toupper(int c);
int				ft_tolower(int c);

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strreset(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strnjoin(const char *s1, const char *s2, size_t n);
char			*ft_strjoinfree(char *s1, const char *s2);
char			*ft_strnjoinfree(char *s1, const char *s2, size_t n);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);

int				ft_cc(const char *s, char c);

/*
** char	*ft_strupr(char *s);
** char	*ft_strlwr(char *s);
*/

/*
** Part III - Tests, maths and conversions
** Custom: ft_isupper, ft_islower. ft_ltostr.
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_ltostr(long num, int base);
char			*ft_itoa(long long int n);
int				ft_atoi(const char *str);
unsigned int	ft_sqrt(unsigned int nb);

int				ft_isupper(int c);
int				ft_islower(int c);

/*
** Part IV - Terminal and file descriptors
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);

/*
** Part V - Linked lists
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
