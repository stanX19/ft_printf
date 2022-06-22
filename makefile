SRCDIR	= srcs/
SRCS	=	$(addprefix $(SRCDIR)ft_, $(addsuffix .c, \
		printf putchar putnbr_base putnbr putstr\
		print_double get_double \
		strdup strlen))

OBJS	=	$(SRCS:.c=.o)

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
TESTDIR = printfTester
TESTGIT = https://github.com/Tripouille/printfTester.git
NAME	= libftprintf.a

run: all
	$(CC) -I. $(CFLAGS) main.c $(NAME) && ./a.out

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o:%.c
	$(CC) -I. $(CFLAGS) $< -c -o $@
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TESTDIR)
	$(RM) ./a.out
re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make && make fclean
$(TESTDIR):
	git clone $(TESTGIT)
.PHONY:			all clean fclean re .c.o
