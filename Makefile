NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c part1/*.c part2/*.c part3/*.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re