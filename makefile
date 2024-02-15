SRCDIR	= srcs
FUNC	= print_functions
UTILS	= utils
SHARED	= shared
SRCS	=	$(addsuffix .c, \
		$(addprefix $(SRCDIR)/ft_, \
			printf read_format match_function) \
		$(addprefix $(SRCDIR)/$(FUNC)/ft_, \
			print_double print_long_double print_percent print_char print_int print_long_int print_long_long_int \
			print_str print_unsigned print_long_unsigned print_long_long_unsigned\
			print_pointer print_hex_lower print_hex_upper print_binary\
			printf_putstr printf_putchar)\
		$(addprefix $(SRCDIR)/$(SHARED)/ft_, \
			get_int get_double get_unsigned_nbr_base format_zero))

OBJDIR		= objs
OBJS		= $(subst $(SRCDIR)/,$(OBJDIR)/,$(subst .c,.o,$(SRCS)))
OBJDIRS		= $(sort $(dir $(OBJS)))

LIBFTDIR	= libft
LIBFT		= $(LIBFTDIR)/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g3
IFLAGS		= -I. -I./headers -I$(LIBFTDIR)
LINKERS		= $(LIBFT)

RM			= rm -rf
TESTDIR		= printfTester
TESTGIT		= https://github.com/Tripouille/printfTester.git
NAME		= libftprintf.a

UP			= \033[1A
FLUSH		= \033[2K

run: all
	$(CC) $(CFLAGS) $(IFLAGS) main.c $(NAME) && ./a.out

bonus: all

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@ar rcsT $(NAME) $(LINKERS) $(OBJS)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIRS) $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) $(LINKERS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(LIBFT):
	make -C $(LIBFTDIR) all

clean:
	@$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TESTDIR)
	$(RM) ./a.out
	make -C $(LIBFTDIR) fclean
	$(RM) $(TESTDIR)

re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make a
$(TESTDIR):
	git clone $(TESTGIT)
.PHONY:			all clean fclean re test run .c.o
