# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 12:42:34 by hcavet            #+#    #+#              #
#    Updated: 2024/12/20 14:27:04 by hcavet           ###   ########.fr        #
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

bonus	:	$(OBJS) $(BOBJS) header
			echo "Linking object files..."
			$(CC) $(CFLAGS) $(OBJS) -I $(IDIR) -o $(NAME) 
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
VFLAGS	=	--leak-check=full
TEST	=	make --no-print-directory test
BTEST	=	make --no-print-directory btest
LOG		=	log
MIN		=	-1000
OS		=	linux
MAX		=	1000
N		=	5

test	:
			echo "$(ORANGE)Testing for n = $(N)$(RESET)"
			echo "N = $(N) TEST" >> $(LOG)
			$(eval ARG = $(shell seq $(MIN) $(MAX) | shuf -n $(N)))
			if [ "$(N)" -le 10 ]; then echo "Initial stack:\t$(ARG)"; fi
			echo -n "Checker:\t"
			$(eval CHECK = $(shell ./push_swap $(ARG) | ./checker_$(OS) $(ARG)))
			if [ "$(CHECK)" = "OK" ]; then echo -n "$(GREEN)"; else echo -n "$(RED)"; fi
			echo "$(CHECK)$(RESET)"
			echo -n "Moves:\t\t"
			./push_swap $(ARG) | wc -l
			$(VGRIND) $(VFLAGS) ./$(NAME) $(ARG) >> $(LOG) 2>&1
			echo "" >> $(LOG)
			echo "$(BLUE)Moves and leak check stored in $(LOG) file.$(RESET)"
			if [ $(N) -le 499 ]; then echo ""; fi

tests	:	all
			echo "Iniating testing..."
			$(TEST) N=2
			$(TEST) N=3
			$(TEST) N=5
			$(TEST)	N=100
			$(TEST) N=500
			echo "$(GREEN)[OK] Testing complete!$(RESET)"

btest	:
			echo "$(ORANGE)Testing for n = $(N)$(RESET)"
			echo "N = $(N) TEST" >> $(LOG)
			$(eval ARG = $(shell seq $(MIN) $(MAX) | shuf -n $(N)))
			if [ "$(N)" -le 10 ]; then echo "Initial stack:\t$(ARG)"; fi
			echo -n "Checker:\t"
			$(eval MCHECK = $(shell ./push_swap $(ARG) | ./checker $(ARG) | sed 's/\x1b\[[0-9;]*m//g'))
			echo "$(MCHECK)"
			echo -n "Checker:\t"
			$(eval SCHECK = $(shell ./push_swap $(ARG) | ./checker_$(OS) $(ARG)))
			echo "$(SCHECK)"
			echo -n "Diff:\t\t"
			./push_swap $(ARG) > instructions
			if [ "$(MCHECK)" = "$(SCHECK)" ]; then echo "$(GREEN)OK$(RESET)"; else echo "$(RED)KO$(RESET)"; fi
			$(VGRIND) $(VFLAGS) ./$(BNAME) $(ARG) < instructions >> $(LOG) 2>&1
			$(RM) instructions
			echo "" >> $(LOG)
			echo "$(BLUE)Moves and leak check stored in $(LOG) file.$(RESET)"
			if [ $(N) -le 499 ]; then echo ""; fi

btests	:	bonus
			echo "Iniating testing..."
			$(BTEST) N=2
			$(BTEST) N=3
			$(BTEST) N=5
			$(BTEST) N=100
			$(BTEST) N=500
			echo "$(GREEN)[OK] Testing complete!$(RESET)"

leaks	:
			$(eval DEF = $(shell awk '/definitely lost:/ {sum += $$4} END {if(sum) print sum; else print "0"}' $(LOG)))
			$(eval IND = $(shell awk '/indirectly lost:/ {sum += $$4} END {if(sum) print sum; else print "0"}' $(LOG)))
			$(eval POS = $(shell awk '/possibly lost:/ {sum += $$4} END {if(sum) print sum; else print "0"}' $(LOG)))
			$(eval TOT = $(shell awk '/lost:/ {sum += $$4} END {if(sum) print sum; else print "0"}' $(LOG)))
			$(eval CDEF = $(if $(shell [ $(DEF) -ge 1 ]), $(RED), $(GREEN)))
			$(eval CIND = $(if $(shell [ $(IND) -ge 1 ]), $(RED), $(GREEN)))
			$(eval CPOS = $(if $(shell [ $(POS) -ge 1 ]), $(RED), $(GREEN)))
			$(eval CTOT = $(if $(shell [ $(TOT) -ge 1 ]), $(RED), $(GREEN)))
			echo "Definitely lost:\t$(CDEF)$(DEF)$(RESET) bytes"
			echo "Indirectely lost:\t$(CIND)$(IND)$(RESET) bytes"
			echo "Possibly lost:\t\t$(CPOS)$(POS)$(RESET) bytes"
			echo "Total:\t\t\t$(CTOT)$(TOT)$(RESET) bytes"
			if [ $(TOT) -ge 1 ]; then echo "$(RED)[KO] Leaks!$(RESET)"; else echo "$(GREEN)[OK] No leaks!$(RESET)"; fi

re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) $(OBJS) $(BOBJS) norm debug clean fclean re header test bonus tests leaks btest btests

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
