# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 14:40:48 by hlibine           #+#    #+#              #
#    Updated: 2024/01/11 14:30:09 by hlibine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = Libft/
BONUS = checker

SRCS_PS = scrs/push_swap.c \

SRCS = scrs/ps_checker_ops_0.c \
		scrs/ps_checker_ops_1.c \
		scrs/ps_checks.c \
		scrs/ps_exit.c \
		scrs/ps_lstfuncs_0.c \
		scrs/ps_lstfuncs_1.c \
		scrs/ps_lstwrk.c \
		scrs/ps_operations_0.c \
		scrs/ps_operations_1.c \
		scrs/ps_operations_2.c \
		scrs/ps_solver_ops_0.c \
		scrs/ps_solver_ops_1.c \
		scrs/ps_sort.c \

BONUS_SRCS = bonus/checker.c \
		bonus/get_next_line/get_next_line.c \
		bonus/get_next_line/get_next_line_utils.c \

OBJS_PS = ${SRCS_PS:.c=.o}
OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

INCLUDE = -L ./Libft -lft

GREEN = \033[0;32m
ORANGE = \033[38;5;208m
RESET = \033[0m

.c.o:
		@echo "$(GREEN)Compiling $<$(RESET)"
		@${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS_PS} ${OBJS}
		@echo "$(ORANGE)Building libft$(RESET)"
		@make -s -C ${LIBFT}
		@echo "$(GREEN)libft built$(RESET)"
		@echo "$(ORANGE)Building $(NAME)$(RESET)"
		@${CC} ${CFLAGS} ${OBJS_PS} ${OBJS} -o ${NAME} ${INCLUDE}
		@echo "$(GREEN)$(NAME) built$(RESET)"

${BONUS}: ${OBJS} ${BONUS_OBJS}
		@echo "$(ORANGE)Building libft$(RESET)"
		@make -s -C ${LIBFT}
		@echo "$(GREEN)libft built$(RESET)"
		@echo "$(ORANGE)Building $(BONUS)$(RESET)"
		@${CC} ${CFLAGS} ${BONUS_OBJS} ${OBJS} -o ${BONUS} ${INCLUDE}
		@echo "$(GREEN)$(BONUS) built$(RESET)"

all: ${NAME} ${BONUS}

bonus: ${BONUS}

clean:
		@echo "$(ORANGE)Cleaning up$(RESET)"
		@${RM} ${OBJS_PS} ${OBJS} ${BONUS_OBJS}
		@cd $(LIBFT) && $(MAKE) -s clean
		@echo "$(GREEN)Clean up successful$(RESET)"

fclean: clean
		@echo "$(ORANGE)Full clean up$(RESET)"
		@${RM} ${NAME} ${BONUS}
		@cd $(LIBFT) && $(MAKE) -s fclean
		@echo "$(GREEN)Full clean up successful$(RESET)"

re: clean all



.PHONY: all clean fclean re bonus