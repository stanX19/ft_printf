SRCDIR	= srcs/
SRCS	=	$(addprefix $(SRCDIR)ft_, $(addsuffix .c, \
		printf putchar putnbr_base putnbr putstr))

OBJS	=	$(SRCS:.c=.o)

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
TESTDIR = printfTester
TESTGIT = https://github.com/Tripouille/printfTester.git
NAME	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TESTDIR)
re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make && make fclean
$(TESTDIR):
	git clone $(TESTGIT)
.PHONY:			all clean fclean re .c.o
