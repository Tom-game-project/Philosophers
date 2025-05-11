# philo

CC	=	cc
CFLAGS = -Wextra -Werror -Wall -g

# rm
RM	=	rm
RMFLAGS	=	-rf

# ar
AR	=	ar
ARFLAGS = rcs



CHOPSTICK_SRC=\
		src/chopstick/set.c\
		src/chopstick/init.c\


PHILOSOPHER_SRC = \
		src/philosopher/brain.c\
		src/philosopher/init.c\
		src/philosopher/set.c\

PRINT_SRC = \
		src/print/print.c\


REAPER_SRC = \
		src/reaper/init.c\
		src/reaper/reaper.c\
		src/reaper/set_reaper_to_philo.c\
		src/reaper/set.c\

TIME_SRC = \
		src/time/time_util.c

SETARGS_SRC = \
		src/setargs/set_args.c

ENTRY_SRC = src/philo.c


SRCS	= $(CHOPSTICK_SRC)\
		$(PHILOSOPHER_SRC)\
		$(PRINT_SRC)\
		$(REAPER_SRC)\
		$(TIME_SRC)\
		$(ENTRY_SRC)\
		$(SETARGS_SRC)


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

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Iinclude $(OBJS) -o $(NAME)

test: $(TEST_NAME) $(U_TEST_OBJ)
	$(CC) $(CFLAGS) $(U_TEST_OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	$(RM) $(RMFLAGS) $(U_TEST_OBJ)
	$(RM) $(RMFLAGS) $(TEST_NAME)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all test clean fclean re
