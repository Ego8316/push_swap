# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ego <ego@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 12:42:34 by hcavet            #+#    #+#              #
#    Updated: 2024/12/19 03:05:04 by ego              ###   ########.fr        #
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
			cost.c				\
			sort_utils.c		\
			boundaries.c		\
			input.c
BSRC	=	checker.c				\
			get_next_line.c			\
			get_next_line_utils.c	\
			push.c					\
			swap.c					\
			rotate.c				\
			reverse_rotate.c		\
			display.c				\
			stack.c					\
			utils.c					\
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
			$(RM) $(OBJS) $(BOBJS) $(LOG)
			echo "$(ORANGE)[OK] All object files have been removed.$(RESET)"

fclean	:	clean
			echo "Removing binary files..."
			$(RM) $(NAME) $(BNAME)
			echo "$(ORANGE)[OK] All binary files have been removed.$(RESET)"

VGRIND	=	valgrind
LOG		=	log
VFLAGS	=	--leak-check=full

test	:	2 3 5 100 500

2		:
			echo "$(ORANGE)Testing for n = 2$(RESET)"
			echo "N = 2 TEST" >> $(LOG)
			$(eval ARG = $(shell shuf -i 0-100 -n 2))
			echo "Initial stack:\t$(ARG)"
			echo -n "Checker:\t"
			./push_swap $(ARG) | ./checker_linux $(ARG)
			echo -n "Moves:\t\t"
			./push_swap $(ARG) | wc -l
			$(VGRIND) $(VFLAGS) ./$(NAME) $(ARG) >> $(LOG) 2>&1
			echo "" >> $(LOG)
			echo "$(BLUE)Moves and leak check stored in $(LOG) file.$(BLUE)\n"


3		:
			echo "$(ORANGE)Testing for n = 3$(RESET)"
			echo "N = 3 TEST" >> $(LOG)
			$(eval ARG = $(shell shuf -i 0-100 -n 3))
			echo "Initial stack:\t$(ARG)"
			echo -n "Checker:\t"
			./push_swap $(ARG) | ./checker_linux $(ARG)
			echo -n "Moves:\t\t"
			./push_swap $(ARG) | wc -l
			$(VGRIND) $(VFLAGS) ./$(NAME) $(ARG) >> $(LOG) 2>&1
			echo "" >> $(LOG)
			echo "$(BLUE)Moves and leak check stored in $(LOG) file.$(BLUE)\n"

5		:
			echo "$(ORANGE)Testing for n = 5$(RESET)"
			echo "N = 5 TEST" >> $(LOG)
			$(eval ARG = $(shell shuf -i 0-100 -n 5))
			echo "Initial stack:\t$(ARG)"
			echo -n "Checker:\t"
			./push_swap $(ARG) | ./checker_linux $(ARG)
			echo -n "Moves:\t\t"
			./push_swap $(ARG) | wc -l
			$(VGRIND) $(VFLAGS) ./$(NAME) $(ARG) >> $(LOG) 2>&1
			echo "" >> $(LOG)
			echo "$(BLUE)Moves and leak check stored in $(LOG) file.$(BLUE)\n"

100		:
			echo "$(ORANGE)Testing for n = 100$(RESET)"
			echo "N = 100 TEST" >> $(LOG)
			$(eval ARG = $(shell shuf -i 0-500 -n 100))
			echo -n "Checker:\t"
			./push_swap $(ARG) | ./checker_linux $(ARG)
			echo -n "Moves:\t\t"
			./push_swap $(ARG) | wc -l
			$(VGRIND) $(VFLAGS) ./$(NAME) $(ARG) >> $(LOG) 2>&1
			echo "" >> $(LOG)
			echo "$(BLUE)Moves and leak check stored in $(LOG) file.$(BLUE)\n"


500		:
			echo "$(ORANGE)Testing for n = 500$(RESET)"
			echo "N = 500 TEST" >> $(LOG)
			$(eval ARG = $(shell shuf -i 0-5000 -n 500))
			echo -n "Checker:\t"
			./push_swap $(ARG) | ./checker_linux $(ARG)
			echo -n "Moves:\t\t"
			./push_swap $(ARG) | wc -l
			$(VGRIND) $(VFLAGS) ./$(NAME) $(ARG) >> $(LOG) 2>&1
			echo "" >> $(LOG)
			echo "$(BLUE)Moves and leak check stored in $(LOG) file.$(BLUE)\n"

re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) $(OBJS) $(BOBJS) norm debug clean fclean re header test bonus 2 3 5 100 500

RED		=	\033[31m
ORANGE	=	\033[38;5;214m
YELLOW	=	\033[33m
GREEN	=	\033[32m
BLUE	=	\033[34m
VIOLET	=	\033[38;5;93m
ITALIC	=	\033[3m
RESET	=	\033[0m

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
