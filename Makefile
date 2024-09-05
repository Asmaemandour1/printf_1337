NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCF = ft_putchar.c ft_putnbr.c ft_putstr.c ft_printf.c ft_puthexa.c ft_putunsigned.c ft_putptr.c

OBJF = $(SRCF:.c=.o)

all: $(NAME)

$(NAME): $(OBJF)
	ar cr $(NAME) $(OBJF)

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJF)

fclean: clean
	rm -f $(NAME)

re: fclean all