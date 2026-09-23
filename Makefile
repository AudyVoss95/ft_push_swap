NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFTDIR	= libft
LIBFT		= $(LIBFTDIR)/libft.a

INCLUDES	= -I include -I $(LIBFTDIR)/include

SRCS		= src/clean_exit.c \
			  src/flags.c \
			  src/indexing.c \
			  src/main.c \
			  src/parse_args.c \
			  src/push.c \
			  src/reverse_rotate.c \
			  src/rotate.c \
			  src/sort_adaptive.c \
			  src/sort_complex.c \
			  src/sort_medium.c \
			  src/sort_simple.c \
			  src/sort_small.c \
			  src/sort_three.c \
			  src/swap.c \
			  src/turk_cost.c \
			  src/turk_move.c

OBJS_DIR	= obj
OBJS		= $(SRCS:src/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(OBJS_DIR)/%.o: src/%.c include/push_swap.h
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re