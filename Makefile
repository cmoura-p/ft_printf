NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

C_SRC	= *.c
C_OBJ	= $(C_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
