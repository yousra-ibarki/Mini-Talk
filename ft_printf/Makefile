# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 05:44:17 by yoibarki          #+#    #+#              #
#    Updated: 2022/11/21 05:44:24 by yoibarki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
SRCS =	 ft_strdup.c \
		ft_printf.c \
		ft_fcthelp.c \
		ft_pointer.c \
		ft_printhex.c \
		ft_itoa.c \
		ft_printunsigned.c \
		add_funt.c 

OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
CC=cc
RM = rm -f
AR = ar -rcs

all: $(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all
