NAME = philo

SRCS = main.c\
		argcheck/argcheck.c\
		ready_samephilo.c\
		thread/limit_thread.c\
		utils/putserror.c utils/putserror2.c utils/ft_atoi.c\

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