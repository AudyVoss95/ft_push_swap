CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
AR = ar rcs
SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/ libft.a

all: $(NAME)
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	@make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re