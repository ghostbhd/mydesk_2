SRCS =	*.c src/*.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror -L/usr/local/lib -I/usr/local/include -lreadline

RM = @rm -rf

AR = @ar -rc

NAME = minishell

LIB = libft/libft.a

sani = -fsanitize=address -g #sanitize
sanitize = $(sani)  && echo "\x1b[36m \n\t$(sani):\x1b[32m Used 💥\n"

all : $(NAME)

$(NAME) : ${SRCS}
	cd libft && make
	${CC} ${CFLAGS} $(LIB) $(SRCS) -o $(NAME) $(sanitize)
	@echo "\x1b[32m \x1b[1m \n✅\tMandatory Compele Success\n\t\x1b[0mPrograme -\x1b[33m ($(NAME))\n\x1b[0m"

clean :
	cd libft && make clean
	${RM} ${NAME}
	@echo "\x1b[31m \x1b[1m \n✅\tDelete [$(NAME)] \x1b[32mSuccess\n\x1b[0m"

fclean : clean
	cd libft && make fclean

re : fclean all
