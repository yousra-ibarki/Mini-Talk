SOURCES = client.c \
		  server.c \
		  server_bonus.c \
		  client_bonus.c 

OBJECTS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
AR = ar -rcs

$(AR) $(OBJECTS)

%.o: %.c 
	$(CC) -c $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM)

re: fclean all

#.phony: all clean fclean re 
