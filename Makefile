# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 10:29:04 by pscott            #+#    #+#              #
#    Updated: 2018/11/29 17:08:56 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	:= make
CC		:= gcc
LD		:= gcc
AR		:= ar
RM		:= rm -f

SRCDIR	:= srcs
INCLDIR := -I libft/includes -I includes/
LIBDIR	:= libft/

CFLAGS	:= -Wall -Wextra $(INCLDIR)
LDFLAGS	:= -L$(LIBDIR) -lft
ARFLAGS	:=

SRCS	:= ft_printf.c convert.c specs.c ft_atoi_move.c exit.c \
			get_next_line.c parse_struct.c ft_strcat_free.c format_int.c
SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:= $(patsubst %.c,%.o,$(SRCS))
DEPS	:= Makefile includes/ft_printf.h
LIB		:= $(LIBDIR)/libft.a
NAME	:= ft_printf

all: $(NAME)

$(LIB):
	$(MAKE) -C libft/

$(NAME): $(LIB) $(OBJS)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS) -fsanitize=address -g3

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

d: all
	@./ft_printf

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re comp
