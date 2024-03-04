NAME = libftprintf.a
SRCS = conv.c ft_printf.c ft_dprintf.c helper.c len.c len2.c print.c print2.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -x $(LIBFT)
	ar rc $(NAME) $(OBJS) *.o
	ranlib $(NAME)
	rm -f *.o

%.o: %.c
	cc $(FLAGS) -g -c $< -o $@ -I$(LIBFT_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re