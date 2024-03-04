make -C ../libft/ft_printf/
cc -Wall -Wextra -Werror -g test2.c  -L../libft/ft_printf/ -I../libft/ft_printf/ -lftprintf
./a.out