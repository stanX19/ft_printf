NAME = libftprintf.a

SRC_DIR = libft/
SRC = $(addprefix $(SRC_DIR)ft_, \
		$(addsuffix .c, \
		putchar putnbr putnbr_base putstr))

OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

LIBCR = ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBCR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(B_SRC) ./libft.h

.PHONY: all clean fclean re norme bonus