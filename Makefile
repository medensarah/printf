# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 04:37:40 by smedenec          #+#    #+#              #
#    Updated: 2025/06/16 20:10:51 by smedenec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c fonction.c temp.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library created: $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	@rm -f $(OBJS)
	@echo "Cleaned objects"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned all"

re: fclean all
	@echo "Rebuild complete"

.PHONY: all clean fclean re
