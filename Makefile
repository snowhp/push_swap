SRCS = push_swap.c\
		error/error.c \
		check/check_arg.c \
		moves/moves.c \
		moves/moves1.c \
		sort/sort.c \
		sort/sort_aux.c \
		sort/sort_aux2.c \
		sort/sort_aux3.c \
		list/list.c \

BONUS = checker.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

BONUS_OBJS = $(BONUS:.c=.o)
EXCLUDED_OBJ := push_swap.o

OBJS = $(SRCS:.c=.o)

NAME = push_swap
CHECKER = checker
LIBFT		= libft.a
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(CHECKER): $(OBJS) $(BONUS_OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(filter-out $(EXCLUDED_OBJ), $(OBJS)) $(BONUS_OBJS) $(LIBFT_LIB) -o $(CHECKER)

debugbonus: $(OBJS) $(BONUS_OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) -g $(filter-out push_swap.c, $(SRCS)) $(BONUS) $(LIBFT_LIB) -o $(CHECKER)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

debug: $(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) -g $(SRCS) $(LIBFT_LIB) -o $(NAME)


$(LIBFT_LIB):
	cd $(LIBFT_DIR) && $(MAKE)

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	$(RM) $(OBJS) $(BNS_OBJS) $(BONUS_OBJS)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	$(RM) $(NAME) $(CHECKER)

re: fclean all
