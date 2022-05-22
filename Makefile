# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phongpai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 15:42:32 by phongpai          #+#    #+#              #
#    Updated: 2022/05/22 16:21:20 by phongpai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/first_va.c srcs/fix_cs.c srcs/fix_pxXperc.c srcs/fix_split.c \
			srcs/ft_printf.c srcs/ft_unitoa.c srcs/make_16.c srcs/make_16p.c \
			srcs/mode.c srcs/print_out.c
LIBFT		= libft/ft_calloc.c libft/ft_itoa.c libft/ft_split.c \
			libft/ft_strjoin.c libft/ft_strlen.c
OBJS		= $(SRCS:.c=.o)
OBJS_LIB	= $(LIBFT:.c=.o)
SRCS_DIR	= srcs
LIB_DIR		= libft
CC			= gcc
CFLAG		= -Wall -Wextra -Werror
NAME		= libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS) $(OBJS_LIB)
	ar -rcs $(NAME) $(OBJS) $(OBJS_LIB)

clean:
	rm -f $(OBJS) $(OBJS_LIB)

fclean:		clean
	rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re