NAME = Minitalk.a
SOURCES = client.c \
		server.c \
		server_bonus.c \
		client_bonus.c 

OBJECTS = $(SOURCES .c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
AR = ar -rcs

all : $(NAME)

$(NAME):$(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c 
	$(CC) -c $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : all clean fclean re 
