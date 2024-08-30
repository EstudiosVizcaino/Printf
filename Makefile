# Makefile for ft_printf

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Source files and object files
SRCS =	ft_printf.c\
		ft_putstr.c\
		ft_putchar.c\
		ft_putdecun.c\
		ft_putptr.c\
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

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
