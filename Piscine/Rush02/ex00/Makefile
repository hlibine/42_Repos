NAME=rush_02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS= srcs/dict_to_string.c \
	  srcs/filter_number.c \
	  srcs/ft_atoi.c \
	  srcs/ft_itoa.c \
	  srcs/ft_putstr.c \
	  srcs/ft_simple_strjoin.c \
	  srcs/ft_strstr.c \
	  srcs/ft_wordfilter.c \
	  srcs/get_billions.c \
	  srcs/get_hundreds.c \
	  srcs/get_millions.c \
	  srcs/get_thousands.c \
	  srcs/print_dicterror.c \
	  srcs/print_error.c \
	  srcs/ft_strstr_zero.c \
	  main.c

OBJS = $(SRCS:.c=.o)
INCLUDES_DIR = includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR)/ -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re