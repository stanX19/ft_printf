NAME = libftprintf.a

SRC_DIR = libft/
SRC = $(addprefix $(SRC_DIR)ft_, \
		$(addsuffix .c, \
		putchar putnbr putnbr_base putstr printf))

OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

LIBCR = ar -rcs

HEADER = ft_printf.h

run: re
	@$(CC) $(CFLAGS) main.c -Ll $(NAME) && ./a.out

all: $(NAME) $(HEADER)

$(NAME): $(OBJ)
	@$(LIBCR) $(NAME) $(OBJ)

$(HEADER): libft/libft.h
	@cp -R $< $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(HEADER)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(B_SRC) ./libft.h

.PHONY: all clean fclean re norme bonus