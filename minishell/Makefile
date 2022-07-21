SRCS =	*.c src/*.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -rf

AR = @ar -rc

NAME = minishell

sani = #sanitize
sanitize = $(sani)  && echo "\x1b[36m \n\t$(sani):\x1b[32m Used 💥\n"

all : $(NAME)

$(NAME) : ${SRCS}
	${CC} ${CFLAGS} $(SRCS) -o $(NAME)
	@echo "\x1b[32m \x1b[1m \n✅\tMandatory Compele Success\n\t\x1b[0mPrograme -\x1b[33m ($(NAME))\n\x1b[0m"

clean :
	${RM} ${NAME}
	@echo "\x1b[31m \x1b[1m \n✅\tDelete [$(NAME)] \x1b[32mSuccess\n\x1b[0m"

fclean : clean

re : fclean all

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

define TAG
@echo "\t$(Cyan)███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
@echo "\t$(Cyan)████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
@echo "\t$(Cyan)██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
@echo "\t$(Cyan)██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
@echo "\t$(Cyan)██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
@echo "\t$(Cyan)╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
endef

ta :
	$(TAG)