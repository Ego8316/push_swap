# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ego <ego@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 12:42:34 by hcavet            #+#    #+#              #
#    Updated: 2024/12/13 04:24:32 by ego              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IDIR	=	include/
SDIR	=	src/

SRC		=	push_swap.c			\
			push.c				\
			swap.c				\
			rotate.c			\
			reverse_rotate.c	\
			display.c			\
			stack.c				\
			utils.c				\
			small_sort.c		\
			sort.c				\
			sort_utils.c		\
			boundaries.c		\
			input.c
BSRC	=	checker.c			\
			push.c				\
			swap.c				\
			rotate.c			\
			reverse_rotate.c	\
			display.c			\
			stack.c				\
			utils.c				\
			input.c
SRCS	=	$(addprefix $(SDIR), $(SRC))
BSRCS	=	$(addprefix $(SDIR), $(BSRC))
OBJS	=	$(SRCS:.c=.o)
BOBJS	=	$(BSRCS:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap
BNAME	=	checker

all		:	$(NAME)

$(NAME)	:	$(OBJS) header
			echo "Linking object files..."
			$(CC) $(CFLAGS) $(OBJS) -I $(IDIR) -o $(NAME) 
			echo "$(GREEN)[OK] push_swap is ready!$(RESET)"

$(BNAME):	bonus

bonus	:	$(BOBJS) header
			echo "Linking object files..."
			$(CC) $(CFLAGS) $(BOBJS) -I $(IDIR) -o $(BNAME) 
			echo "$(GREEN)[OK] checker is ready!$(RESET)"

.c.o	:
			echo "Compiling $<..."
			$(CC) $(CFLAGS) -I $(IDIR) -c $< -o $(<:.c=.o)

norm	:
			norminette -R CheckForbiddenSourceHeader $(SRCS) $(IDIR)

clean	:
			echo "Removing object files..."
			$(RM) $(OBJS) $(BOBJS)
			echo "$(ORANGE)[OK] All object files have been removed.$(RESET)"

fclean	:	clean
			echo "Removing binary files..."
			$(RM) $(NAME) $(BNAME)
			echo "$(ORANGE)[OK] All binary files have been removed.$(RESET)"

re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) $(OBJS) $(BOBJS) norm debug clean fclean re header test bonus

RED     = \033[31m
ORANGE  = \033[38;5;214m
YELLOW  = \033[33m
GREEN   = \033[32m
BLUE    = \033[34m
VIOLET  = \033[38;5;93m
ITALIC  = \033[3m
RESET   = \033[0m

header	:
			echo "======================================================="
			echo "$(RED) ____  _     ____  _           ____  _      ____  ____ $(RESET)"
			echo "$(RED)/  __\/ \ /\/ ___\/ \ / |     / ___\/ \  /|/  _ \/  __\\ $(RESET)"
			echo "$(YELLOW)|  \/|| | ||||___ | |_| |     | \__ | |  ||| / \||  \/|$(RESET)"
			echo "$(GREEN)|  __/| \_/|\___ || | | |     \___ || |/\||| |-|||  __/$(RESET)"
			echo "$(BLUE)\_/   \____/\____/\_/ \ |_____\____/\_/  \|\_/ \|\_/   $(RESET)"
			echo "$(BLUE)                         \____\                        $(RESET)"
			echo "$(ITALIC)$(VIOLET)                     by Ego\n$(RESET)"
			echo "=======================================================\n"
