# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytuan-ju <ytuan-ju@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 22:24:42 by ytuan-ju          #+#    #+#              #
#    Updated: 2022/05/26 15:34:28 by ytuan-ju         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR	= srcs/
SRCS	=	$(addprefix $(SRCDIR)ft_, $(addsuffix .c, \
		printf putchar putnbr_base putnbr putstr))

OBJS	=	$(SRCS:.c=.o)

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
					ar rcs $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)
re:						fclean $(NAME)

.PHONY:			all clean fclean re .c.o
