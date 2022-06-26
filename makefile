SRCDIR	= srcs/
FUNC	= print_functions/
UTILS	= utils/
SHARED	= shared/
SRCS	=	$(addsuffix .c, \
		$(addprefix $(SRCDIR)ft_, \
			printf read_format format_match) \
		$(addprefix $(SRCDIR)$(FUNC)ft_, \
			print_double print_long_double print_percent print_char print_int print_long_int print_long_long_int \
			print_str print_unsigned print_pointer print_hex_lower print_hex_upper)\
		$(addprefix $(SRCDIR)$(SHARED)ft_, \
			get_int get_double get_unsigned get_unsigned_nbr_base format_zero)\
		$(addprefix $(SRCDIR)$(UTILS)ft_, \
			strdup strlen strcpy strncpy putchar putnbr_base putstr memmove isdigit))

OBJS	=	$(subst .c,.o,$(SRCS))

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
RM			=	rm -rf
TESTDIR = printfTester
TESTGIT = https://github.com/Tripouille/printfTester.git
NAME	= libftprintf.a

run: all
	$(CC) -I. $(CFLAGS) main.c $(NAME) && ./a.out
bonus: all
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
%.o:%.c
	$(CC) -I. $(CFLAGS) $< -c -o $@
	@echo "\033[1A\033[2K\033[1A"
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
