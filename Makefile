NAME = libftprintf.a
SRCS =  print_char.c \
		print_str.c \
		print_nbr.c \
		print_hex.c \
		print_format.c \
		print_substr.c \
		ft_printf.c \

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
FLOGS = 
TEST_DIR = test

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 
	ranlib $(NAME)

%.o: %.c
	cc $(FLAGS) -g -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re