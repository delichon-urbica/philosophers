NAME := philo

CC := gcc

CFLAGS := -Wall -Wextra -Werror

SOURCE := philo.c init.c routine.c routine_checks.c utils.c

OBJS := $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo all files compiled

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo all clean
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
