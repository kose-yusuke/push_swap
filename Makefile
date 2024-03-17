NAME = push_swap
CFLAGS    = -Wall -Wextra -Werror -g -fsanitize=address
# CFLAGS    = -Wall
LIBFT_DIR = ./lib/libft
INCLUDE = -I $(LIBFT_DIR)/include
LIB = -L $(LIBFT_DIR) -l ft
SRC_DIR = ./
MANDATORY_FILES = main.c push_ops.c node_utils.c swap_ops.c swap_ops2.c utils.c error_handling.c small_sort.c sort.c compress.c
MANDATORY_OBJS = $(addprefix $(SRC_DIR)/, $(MANDATORY_FILES:.c=.o))
# BONUS_FILES = so_long_bonus.c
BONUS_OBJS = $(addprefix $(SRC_DIR)/, $(BONUS_FILES:.c=.o))

LIBFT_A = ./lib/libft/libft.a

ifdef IS_BONUS_FILES
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MANDATORY_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

bonus:
	make IS_BONUS=1

.c.o: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re