SOURCES = client.c server.c
OBJECTS = $(SOURCES .c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : server client

server: server.o 
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c 
	$(CC) -c $(CFLAGS)

 : 
	make -C libft

clean : 
	rm -f $(OBJECTS)
	make -C libft clean

fclean : clean
	rm -f server client libft/libft.a

re : fclean all

.phony : all libft clean fclean re 
