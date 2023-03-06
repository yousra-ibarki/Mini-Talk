SERVER		=	ft_server/server.c
CLIENT		=	ft_client/client.c
FT_PRINTF	=	cd ft_printf && make
PRINTF		=	ft_printf/libftprintf.a
SERVER_SRC	=	$(SERVER)
CLIENT_SRC	=	$(CLIENT)
SERVER_OBJS	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)
OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

GCC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
SERVER_NAME	=	server.a
CLIENT_NAME	=	client.a
NAME		=	minitalk

all: $(NAME)

$(NAME): printfcomp ft_server ft_client

printfcomp:
	@$(FT_PRINTF)

ft_server: $(SERVER_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) $(PRINTF) -o $(SERVER_NAME)

ft_client: $(CLIENT_OBJS)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS) $(PRINTF) -o $(CLIENT_NAME)

clean:
	@rm -rf $(OBJS)
	@cd ft_printf && make clean

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@cd ft_printf && make fclean

.c.o:
	@${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY: all minitalk server client clean fclean re ft_printf printf