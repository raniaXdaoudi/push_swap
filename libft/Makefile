# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rania <rania@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 09:46:37 by radaoudi          #+#    #+#              #
#    Updated: 2022/09/23 21:43:38 by rania            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRCS		= ft_putnbr.c ft_putstr.c ft_size_int.c ft_unsi_putnbr.c ft_printf.c ft_check_base.c ft_print_hexa.c ft_print_char.c ft_print_decimal.c ft_print_pointeur.c ft_print_string.c ft_print_unsi.c get_next_line.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS:.c=.o}
HEADER		= includes
FOLDER		= srcs

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

${NAME}:	${OBJS} bonus
			ar -rcs ${NAME} ${OBJS}

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} libft.a

re:			fclean all

bonus:		${OBJS} ${BONUS_OBJS}
			ar -rcs ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY:         all clean fclean re
