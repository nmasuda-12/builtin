NAME = built

CC = cc
CFLAGS = -Wall -Wextra -Werror

MAIN_SRCS = echo.c \
	   		pwd.c \
	   		env.c \
			unset.c \
			exit.c \
			export.c \
			cd.c \
	   		main.c

UTIL_SRCS = utils/ft_atoi.c \
			utils/ft_memcmp.c \
			utils/ft_putstr_fd.c \
			utils/ft_strncmp.c \
			utils/ft_strlen.c \
			utils/ft_strdup.c \
			utils/ft_strjoin.c \
			utils/ft_export_strjoin.c \
			utils/check.c \
			utils/error.c \
			utils/free_all.c

SRCS = $(MAIN_SRCS) $(UTIL_SRCS)

$(NAME)	: 
	$(CC) $(CFLAG) $(SRCS) -o $@

fclean :
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) $(NAME)