# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rania <rania@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 19:29:13 by rania             #+#    #+#              #
#    Updated: 2022/10/03 13:06:19 by rania            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= srcs
SRCS_NAME	= main.c \
				create_stack.c \
				check_errors.c \
				move.c \
				stack_utils.c \
				short_sort.c
OBJS_DIR	= objs
OBJS_NAME	= ${SRCS_NAME:.c=.o}
SRCS		= $(addprefix $(SRCS_DIR)/,$(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_DIR)/,$(OBJS_NAME))
LFT			= libft.a
INC			= -I ./includes -I ./libft
LIB			= -L ./libft -lft

NAME	= push_swap

CC		= gcc
RM		= rm -f
CFLAGS	= $(INC) -Wall -Wextra -Werror -fsanitize=address -g3
all:		$(LFT) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LFT):
			@make -s -C libft

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
			@mkdir $(OBJS_DIR) 2> /dev/null || true
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJS) $(OBJS_DIR)

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
