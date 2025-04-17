# philo

CC	=	cc
CFLAGS = -Wextra -Werror -Wall -g

# rm
RM	=	rm
RMFLAGS	=	-rf

# ar
AR	=	ar
ARFLAGS = rcs

SRCS	=	philo/philo.c
OBJS	=	$(SRCS:.c=.o)

# optional
# unit test src
TEST_NUM	?=	00
TEST_DIR	=	tests/
U_TEST_SRC	=	$(TEST_DIR)test$(TEST_NUM).c

EXAMPLE_FILE	?=	examples/time_example00.c

U_TEST_OBJ	=	$(U_TEST_SRC:.c=.o)
TEST_NAME	=	test
EXAMPLE_NAME	=	example

NAME = philo/philo


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

test: $(TEST_NAME) $(U_TEST_OBJ)
	$(CC) $(CFLAGS) $(U_TEST_OBJ) -o $@

example: $(EXAMPLE_FILE)
	$(CC) $(CFLAGS) $(EXAMPLE_FILE) -o $(EXAMPLE_NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	$(RM) $(RMFLAGS) $(U_TEST_OBJ)
	$(RM) $(RMFLAGS) $(TEST_NAME)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all test clean fclean re example
