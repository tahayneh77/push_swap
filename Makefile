NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_SRCS = utils.c \
	parser_utils.c \
	split.c \
	parser.c \
	stack_init.c \
	stack_utils.c \
	operations_swap.c \
	operations_push.c \
	operations_rotate.c \
	operations_reverse.c \
	op_exec.c \
	op_exec_rot.c \
	op_exec_rev.c \
	bench_record.c \
	bench.c \
	disorder.c \
	sort_small.c \
	strat_simple.c \
	strat_medium.c \
	strat_targets.c \
	strat_complex.c \
	strat_bounce.c

SRCS = push_swap.c $(COMMON_SRCS)
BONUS_SRCS = checker.c checker_utils.c $(COMMON_SRCS)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
