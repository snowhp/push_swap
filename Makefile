SRCS = push_swap.c\
		error/error.c \
		check_arg.c \
		moves.c \
		sort/sort.c \

OBJS = $(SRCS:.c=.o)

NAME = push_swap
LIBFT		= libft.a
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

debug: $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -g $(SRCS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT):
	cd $(LIBFT_DIR) && $(MAKE)

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all
