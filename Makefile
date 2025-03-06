NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

run: re
	@valgrind --leak-check=full --show-leak-kinds=all ./a.out hola.txt

.PHONY: all clean fclean re