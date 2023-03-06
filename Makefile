# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoibarki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 10:19:31 by yoibarki          #+#    #+#              #
#    Updated: 2023/03/06 10:19:33 by yoibarki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SERVER		=	ft_server/server.c
CLIENT		=	ft_client/client.c
FT_PRINTF	=	cd ft_printf && make
PRINTF		=	ft_printf/libftprintf.a

SERVER_BONUS = ft_server/server_bonus.c
CLIENT_BONUS = ft_client/client_bonus.c

SERVER_SRC	=	$(SERVER)
CLIENT_SRC	=	$(CLIENT)

SERVER_SRC_BONUS = $(SERVER_BONUS)
CLIENT_SRC_BONUS = $(CLIENT_BONUS)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

SERVER_OBJS_BONUS = $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRC_BONUS:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

OBJS_SRC    =   $(SERVER_OBJS_BONUS) \
				$(CLIENT_OBJS_BONUS)

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror

SERVER_NAME	=	server
CLIENT_NAME	=	client

SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

NAME		=	minitalk

all: $(NAME)

$(NAME): printfcomp server client server_bonus client_bonus

printfcomp:
	@$(FT_PRINTF)

server: $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER_OBJS) $(PRINTF) -o $(SERVER_NAME)

client: $(CLIENT_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) $(PRINTF) -o $(CLIENT_NAME)

server_bonus: $(SERVER_OBJS_BONUS)
		@$(CC) $(FLAGS) $(SERVER_OBJS_BONUS) $(PRINTF) -o $(SERVER_BONUS_NAME)

client_bonus: $(CLIENT_OBJS_BONUS)
		@$(CC) $(FLAGS) $(CLIENT_OBJS_BONUS) $(PRINTF) -o $(CLIENT_BONUS_NAME)

clean:
	@rm -rf $(OBJS) $(OBJS_SRC)
	@cd ft_printf && make clean

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)
	@cd ft_printf && make fclean

%.o:%.c 
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all minitalk server client clean fclean re ft_printf printf bonus 
