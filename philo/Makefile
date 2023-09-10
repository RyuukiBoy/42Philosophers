NAME= philo
CC= cc
CFLAGS= -Wall -Wextra -Werror -pthread #-fsanitize=thread -g3

SRCS= philo.c init.c ft_atoi.c actions.c philo_utils.c check_death.c
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re