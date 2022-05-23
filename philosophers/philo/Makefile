SRCS =	main.c utils.c fill.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -rf

AR = @ar -rc

NAME = philo

# LIB = src/lib.a

sanitize = -fsanitize=thread -g && echo "\x1b[36m \n\t-fsanitize=thread:\x1b[32m Used 💥\n"

all : $(NAME)

$(NAME) : ${SRCS}
	${CC} -pthread ${CFLAGS} $(SRCS) -o $(NAME)
	@echo "\x1b[32m \x1b[1m \n✅\tMandatory Compele Success\n\t\x1b[0mPrograme name -\x1b[33m ($(NAME))\n\x1b[0m"

clean :
	${RM} ${NAME}
	@echo "\x1b[31m \x1b[1m \n✅\tDelete [$(NAME)] \x1b[32mSuccess\n\x1b[0m"

fclean : clean

re : fclean all