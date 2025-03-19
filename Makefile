NAME = push_swap
LIBFT_DIR = ft_libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_operations.c ft_operations_a.c ft_operations_b.c ft_stack_sort.c ft_check_stack.c ft_check_stack_second.c ft_stack_init.c

SRC_BONUS = checker.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_operations_bonus.c ft_operations_a_bonus.c ft_operations_b_bonus.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_check_stack.c ft_stack_init.c ft_check_stack_second.c

OBJS = $(SRC:%.c=%.o)

OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(LIBFT) $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o checker

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean
