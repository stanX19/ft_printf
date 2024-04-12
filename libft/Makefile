SRCDIR			= .
SRCS			= $(wildcard $(SRCDIR)/*.c)
# SRCS			= $(addprefix $(SRCDIR)/,\
# 	ft_atoi.c \
# 	ft_bzero.c \
# 	ft_calloc.c \
# 	ft_isalnum.c \
# 	ft_isalpha.c \
# 	ft_isascii.c \
# 	ft_isdigit.c \
# 	ft_isprint.c \
# 	ft_itoa.c \
# 	ft_lstadd_back.c \
# 	ft_lstadd_front.c \
# 	ft_lstclear.c \
# 	ft_lstdelone.c \
# 	ft_lstiter.c \
# 	ft_lstlast.c \
# 	ft_lstmap.c \
# 	ft_lstnew.c \
# 	ft_lstsize.c \
# 	ft_memchr.c \
# 	ft_memcmp.c \
# 	ft_memcpy.c \
# 	ft_memmove.c \
# 	ft_memset.c \
# 	ft_putchar_fd.c \
# 	ft_putendl_fd.c \
# 	ft_putnbr_fd.c \
# 	ft_putstr_fd.c \
# 	ft_split.c \
# 	ft_strchr.c \
# 	ft_strcpy.c \
# 	ft_strdup.c \
# 	ft_striteri.c \
# 	ft_strjoin.c \
# 	ft_strlcat.c \
# 	ft_strlcpy.c \
# 	ft_strlen.c \
# 	ft_strmapi.c \
# 	ft_strncmp.c \
# 	ft_strndup.c \
# 	ft_strnstr.c \
# 	ft_strrchr.c \
# 	ft_strtrim.c \
# 	ft_substr.c \
# 	ft_tolower.c \
# 	ft_toupper.c \
# )
OBJDIR			= objs
OBJS			= $(subst $(SRCDIR)/,$(OBJDIR)/,$(subst .c,.o,$(SRCS)))
OBJDIRS			= $(sort $(dir $(OBJS)))

HEADERS			= libft.h

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror #-fsanitize=address -g3
IFLAGS			= -I.
RM				= rm -rf

NAME			= libft.a

UP				= \033[1A
FLUSH			= \033[2K

TESTER			= Tester
TESTER_SUB		= $(TESTER)/libft-war-machine


all: $(NAME)

bonus: $(NAME)

# $(TESTER):
# 	git clone https://github.com/FranFrau/Supreme-Tester-Libft $(TESTER)
# 	cd $(TESTER); sh tester.sh
# 	export FILE=$(TESTER_SUB)/my_config.sh; sed "s|PATH_LIBFT=\"\.\./\"|PATH_LIBFT=\"$$(pwd)\"|g" $$FILE > temp; cat temp > $$FILE; $(RM) temp

# test: $(TESTER)
# 	cd $(TESTER); sh tester.sh

# tclean:
# 	@$(RM) $(TESTER) libftTester ../libft-unit-test ../libft_tester

$(TESTER):
	git clone https://github.com/Tripouille/libftTester.git $(TESTER)

test: $(TESTER)
	make -C $(TESTER) a

tclean:
	@$(RM) $(TESTER)
# rename:
#	find . -type f -name "ft_lst*" | while read -r file; do new_file="$${file%.c}.c"; mv $$file $$new_file; done;

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJDIRS):
	mkdir -p $(OBJDIR)
	@echo "$(UP)$(FLUSH)$(UP)"
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIRS) $(HEADERS) 
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
#@$(RM) $(TESTER)

push:
	@echo -n "Commit name: "; read name; make fclean; make tclean; git add .; git commit -m "$$name"; git push

re: fclean $(NAME)

.PHONY: all clean fclean re test tclean push
