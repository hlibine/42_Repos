# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:16:12 by hlibine           #+#    #+#              #
#    Updated: 2024/01/23 16:22:41 by hlibine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = Libft/
BONUS = checker

SRCS_PX = srcs/pipex.c \

SRCS = srcs/px_utils.c \

OBJS_PX = ${SRCS_PX:.c=.o}
OBJS = ${SRCS:.c=.o}

INCLUDE = -L ./Libft -lft

GREEN = \033[0;32m
ORANGE = \033[38;5;208m
RESET = \033[0m

.c.o:
		@echo "$(GREEN)Compiling $<$(RESET)"
		@${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS_PX} ${OBJS}
		@echo "$(ORANGE)Building libft$(RESET)"
		@make -s -C ${LIBFT}
		@echo "$(GREEN)libft built$(RESET)"
		@echo "$(ORANGE)Building $(NAME)$(RESET)"
		@${CC} ${CFLAGS} ${OBJS_PX} ${OBJS} -o ${NAME} ${INCLUDE}
		@echo "$(GREEN)$(NAME) built$(RESET)"

all: ${NAME}

clean:
		@echo "$(ORANGE)Cleaning up$(RESET)"
		@${RM} ${OBJS_PX}
		@cd $(LIBFT) && $(MAKE) -s clean
		@echo "$(GREEN)Clean up successful$(RESET)"

fclean: clean
		@echo "$(ORANGE)Full clean up$(RESET)"
		@${RM} ${NAME}
		@cd $(LIBFT) && $(MAKE) -s fclean
		@echo "$(GREEN)Full clean up successful$(RESET)"

re: clean all



.PHONY: all clean fclean re