# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 17:48:39 by albgonza          #+#    #+#              #
#    Updated: 2022/10/28 11:44:06 by albgonza         ###   ########.fr        #
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
				extra3.c

OBJS	:= $(SRC:.c=.o)
CC	= clang
CFLAGS	= -Wall -Werror -Wextra
RM	= rm -rf

all: norm libft libmlx $(NAME)

libft:
	@echo "$(COLOR_GREEN)$(BOLD)Compiling libft 📔$(RESET)"
	@$(MAKE) -C $(LIBFT)
	

libmlx:
	@echo "$(COLOR_GREEN)$(BOLD)Compiling MLX42 🎥$(RESET)"
	@$(MAKE) -C $(LIBMLX)
	

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) $(HEADER) -o $(NAME)

%.o : %.c
	$(CC) $(HEADER) -o $@ -c $<

clean:
	@echo "$(COLOR_GREEN)$(BOLD)Cleaning all '.o' items 🧹$(RESET)"
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
	

fclean: clean
	@echo "$(COLOR_GREEN)$(BOLD)Cleaning the library 📚$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean
	

re: fclean all

norm: 
	norminette *.c
	norminette *.h

.PHONY: all bonus clean fclean re
