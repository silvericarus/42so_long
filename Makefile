# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 17:48:39 by albgonza          #+#    #+#              #
#    Updated: 2022/10/19 18:15:09 by albgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
LIBFT	= lib/libft
LIBMLX	= lib/MLX42
HEADER	= -I so_long -I $(LIBMLX)/include/MLX42 -I $(LIBFT)
LFLAGS	= -L$(LIBFT) -lft  -L$(LIBMLX) -lmlx42 
LIBS	= -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/
COLOR_GREEN := \033[32;1m
RESET	:= \033[0m
BOLD	:= \033[1m

SRC	:= so_long.c \
				check.c    \
				keys.c     \
				extra.c  \
				extra2.c \
				booleans.c

OBJS	:= $(SRC:.c=.o)
CC	= clang
CFLAGS	= -Wall -Werror -Wextra
RM	= rm -rf

all: libft libmlx $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)
	@echo "$(COLOR_GREEN)$(BOLD)Compiling libft 📔$(RESET)"

libmlx:
	@$(MAKE) -C $(LIBMLX)
	@echo "$(COLOR_GREEN)$(BOLD)Compiling MLX42 🎥$(RESET)"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) $(HEADER) -o $(NAME)

%.o : %.c
	$(CC) $(HEADER) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
	@echo "$(COLOR_GREEN)$(BOLD)Cleaning all '.o' items 🧹$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean
	@echo "$(COLOR_GREEN)$(BOLD)Cleaning all items ⛏$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
