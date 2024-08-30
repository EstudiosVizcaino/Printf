# Makefile for ft_printf

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Source files and object files
SRCS = ft_printf.c\ # Add other source files here
		ft_putstr.c\
		ft_putchar.c\
		ft_putdec.c\
		ft_putdecun.c\
		ft_puthex.c\
		ft_puthexcaps.c\
		ft_putptr\
		ft_strlen.c\
		ft_putnbr.c\
		ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

# Library name
NAME = libftprintf.a

# Compile rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
