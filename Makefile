CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = push_swap.c\
		ft_checknumbers.c\

OFILES = $(addprefix $(OBJ_DIR)/,$(CFILES:.c=.o))

OBJ_DIR = ./OBJ

SRC_DIR = ./SRC

LIB = libft/libft.a

INC = includes/push_swap.h

NAME = push_swap

$(NAME) : $(LIB) $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) $(LIB) -o $(NAME)
	@echo "done for push_swap"

$(LIB): force
	@make -C libft

force:

$(OBJ_DIR) :
	@mkdir OBJ

$(OFILES) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC) | $(OBJ_DIR)
	@$(CC) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make clean -C libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft

re : fclean all

all : $(NAME)

norme :
	@norminette **/*.c
	@norminette **/*.h
