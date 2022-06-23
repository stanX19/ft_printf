SRCDIR	= srcs/
FUNC	= print_functions/
UTILS	= utils/
SHARED	= shared/
SRCS	=	$(addsuffix .c, \
		$(addprefix $(SRCDIR)ft_, \
			printf read_format format_match) \
		$(addprefix $(SRCDIR)$(FUNC)ft_, \
			print_double print_percent print_char print_int print_long_int print_long_long_int)\
		$(addprefix $(SRCDIR)$(SHARED)ft_, \
			get_int)\
		$(addprefix $(SRCDIR)$(UTILS)ft_, \
			strdup strlen strcpy putchar putnbr_base putstr))

OBJS	=	$(subst .c,.o,$(SRCS))

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
	@ar rcs $(NAME) $(OBJS)
%.o:%.c
	$(CC) -I. $(CFLAGS) $< -c -o $@
clean:
	@$(RM) $(OBJS)

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
