SRCS = ft_printf.c
SRC_LIB = $(addprefix library/, ft_putchar.c ft_putstr.c ft_putaddress.c ft_puthexa.c ft_putnbr.c ft_putunsigned.c)


OBJS = $(SRCS:.c=.o)
OBJS_LIB = $(SRC_LIB:.c=.o)
HEADER = ft_printf.h

NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIB = ranlib
INC_DIR = .

.c.o:
	$(CC) -I$(INC_DIR) $(CFLAGS) -c $< -o $(<:.c=.o)
# %.o: %.c
# 	$(CC) -I$(INC_DIR) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(OBJS_LIB)
	$(LIBC) $(NAME) $(OBJS) $(OBJS_LIB)
	$(LIB) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_LIB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re