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
			get_int get_double get_unsigned_nbr_base print_buf_with_int_fmt print_buf_with_str_fmt\
			print_buf_with_double_fmt))

OBJDIR		= objs
OBJS		= $(subst $(SRCDIR)/,$(OBJDIR)/,$(subst .c,.o,$(SRCS)))
OBJDIRS		= $(sort $(dir $(OBJS)))

LIBFTDIR	= libft
LIBFT		= $(LIBFTDIR)/libft.a
LIB_OBJDIR	= $(OBJDIR)/$(LIBFTDIR)

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
	$(CC) $(CFLAGS) $(IFLAGS) main.c $(NAME)
	./a.out


bonus: all

all: $(NAME)

$(NAME): $(OBJDIRS) $(OBJS) $(LIBFT)
	mkdir -p $(LIB_OBJDIR); cd $(LIB_OBJDIR); ar -x ../../$(LIBFT)
	ar -rcs $(NAME) $(LIB_OBJDIR)/*.o $(OBJS)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(HEADERS) $(OBJDIRS) $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(LIBFT):
	make -C $(LIBFTDIR) all

clean:
	@$(RM) $(OBJS)
	@$(RM) $(LIB_OBJDIR)
	
fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) ./a.out
	@make -C $(LIBFTDIR) fclean
	@$(RM) $(TESTDIR)

re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make a

$(TESTDIR):
	git clone $(TESTGIT)

push:
	@echo -n "Commit name: "; read name; make fclean; git add .; git commit -m "$$name"; git push

.PHONY:			all clean fclean re test run .c.o
