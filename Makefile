NAME = built

CC = cc
CFLAGS = -Wall -Wextra -Werror

MAIN_SRCS = echo.c \
	   		pwd.c \
	   		env.c \
			unset.c \
			exit.c \
	   		main.c

UTIL_SRCS = utils/ft_atoi.c \
			utils/ft_strncmp.c \
			utils/ft_strlen.c \
			utils/ft_memmove.c \
			utils/check.c \
			utils/error.c

SRCS = $(MAIN_SRCS) $(UTIL_SRCS)

$(NAME)	: 
	$(CC) $(CFLAG) $(SRCS) -o $@

fclean :
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) $(NAME)