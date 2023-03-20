NAME = philo

SRCS = main.c\
		argcheck/argcheck.c\
		utils/putserror.c\

OBJS = $(SRCS:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror -I includes -pthread

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(NAME)

fclean: clean
	rm -f all

re: fclean all