SRCDIR	= srcs
FUNC	= print_functions
UTILS	= utils
SHARED	= shared
SRCS	=	$(addsuffix .c, \
		$(addprefix $(SRCDIR)/ft_, \
			printf read_format match_function) \
		$(addprefix $(SRCDIR)/$(FUNC)/ft_print_, \
			double long_double percent char int long_int long_long_int \
			str unsigned long_unsigned long_long_unsigned\
			pointer hex_lower hex_upper binary)\
		$(addprefix $(SRCDIR)/$(SHARED)/ft_, \
			printf_putstr printf_putchar\
			get_int get_double get_unsigned_nbr_base print_buf_with_int_fmt print_buf_with_str_fmt\
			print_buf_with_double_fmt))

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
	$(CC) $(CFLAGS) $(IFLAGS) main.c $(NAME)
	./a.out


bonus: all

all: $(NAME)

$(NAME): $(OBJDIRS) $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(HEADERS) $(OBJDIRS) $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(LIBFT):
	make -C $(LIBFTDIR) all

clean:
	@$(RM) $(OBJDIR)*.o
	
fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) ./a.out
	@make -C $(LIBFTDIR) fclean

re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make a

$(TESTDIR):
	git clone $(TESTGIT)

push:
	@echo -n "Commit name: "; read name; make fclean; git add .; git commit -m "$$name"; git push

.PHONY:			all clean fclean re test run .c.o
