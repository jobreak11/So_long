NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include

Libft	:= ./include/libft/libft.a
LIBS	:= $(LIBMLX)/build/libmlx42.a $(Libft) -ldl -lglfw -pthread -lm 
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: lft libmlx $(NAME)

lft :
	@make -C include/libft

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(CFLAGS) $ $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)/build
	@make fclean -C include/libft

re: clean all

.PHONY: all clean fclean re libmlx