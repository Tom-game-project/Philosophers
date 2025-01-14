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
U_TEST_OBJ	=	$(U_TEST_SRC:.c=.o)
TEST_NAME	=	test

NAME = philo


all: $(NAME)

$(NAME): $(SRCS)

test: $(TEST_NAME) $(U_TEST_OBJ)
	$(CC) $(CFLAGS) $(U_TEST_OBJ) -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	$(RM) $(RMFLAGS) $(U_TEST_OBJ)
	$(RM) $(RMFLAGS) $(TEST_NAME)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all test clean fclean re
