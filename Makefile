# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 10:29:04 by pscott            #+#    #+#              #
#    Updated: 2018/12/18 11:31:14 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
RM		:= rm -f

SRCDIR	:= srcs
LIBDIR	:= srcs/libft
INCLDIR := -I includes/

CFLAGS	:= -Wall -Wextra $(INCLDIR)
ARFLAGS	:=

LIBS	:= ft_atoi.c  ft_bzero.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c  ft_itoa.c  ft_litoa.c ft_llitoa.c ft_lstadd.c  ft_lstappend.c  ft_lstdel.c  ft_lstdelone.c  ft_lstiter.c  ft_lstlen.c  ft_lstmap.c  ft_lstnew.c  ft_lstrmdup.c  ft_lstsort.c  ft_memalloc.c  ft_memccpy.c  ft_memchr.c  ft_memcmp.c  ft_memcpy.c  ft_memdel.c  ft_memmove.c  ft_memset.c  ft_putchar.c  ft_putchar_fd.c  ft_putendl.c  ft_putendl_fd.c  ft_putnbr.c  ft_putnbr_fd.c  ft_putstr.c  ft_putstr_fd.c  ft_strcat.c  ft_strchr.c  ft_strclr.c  ft_strcmp.c  ft_strcpy.c  ft_strdel.c  ft_strdup.c  ft_strequ.c  ft_striter.c  ft_striteri.c  ft_strjoin.c  ft_strlcat.c  ft_strlen.c  ft_strmap.c  ft_strmapi.c  ft_strncat.c  ft_strncmp.c  ft_strncpy.c  ft_strnequ.c  ft_strnew.c  ft_strnstr.c  ft_strrchr.c  ft_strrev.c  ft_strsplit.c  ft_strstr.c  ft_strsub.c  ft_strtrim.c  ft_tolower.c  ft_toupper.c

NEWS	:= ft_printf.c converters.c ft_atoi_move.c exit.c parse_struct.c ft_strcat_free.c format_int.c ft_uitoa.c get_len.c getters.c utils.c spec_init.c format_char.c format_unsigned.c format_string.c get_ulen.c format_lint.c format_llint.c format_num.c ft_hitoa.c ft_hhitoa.c null_data.c get_preci_flags.c format_conv.c conv_helper.c
LIBS	:= $(addprefix $(LIBDIR)/, $(LIBS))
NEWS	:= $(addprefix $(SRCDIR)/, $(NEWS))
SRCS	:= $(LIBS) $(NEWS)
OBJS	:= $(SRCS:.c=.o)
DEPS	:= Makefile includes/ft_printf.h includes/libft.h
NAME	:= libftprintf.a

all: $(NAME)

d: all
	@gcc main.c $(INCLDIR) $(NAME)
	@./a.out | cat -e
	@rm a.out

val:
	@gcc main.c $(INCLDIR) $(NAME)
	@valgrind --leak-check=yes ./a.out

fsa:
	@gcc main.c $(INCLDIR) $(NAME) -fsanitize=address -g3
	@./a.out

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all

.PHONY: all clean fclean re comp
