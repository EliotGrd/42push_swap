
NAME = push_swap

SRC_PATH = srcs/
LIBFT_PATH = libft/
LIBFT_AR = $(LIBFT_PATH)libft.a

SRC = push_swap.c parsing.c stack_push.c stack_rotate.c stack_revrotate.c \
	  stack_swap.c stack_utils.c divide.c conquer.c split_from_to.c \
	  three_sort.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
DPD = $(SRC:.c=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -g
INCS = includes/push_swap.h
INC = -Iincludes -I$(LIBFT_PATH)/includes

PURPLE = \033[0;35m
NC = \033[0m

all: $(LIBFT_AR) $(NAME)

$(NAME): $(OBJ) $(INCS)
	@echo "\n$(PURPLE)  Compiling Push_swap...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_AR) $(INC) -o $(NAME)
	@echo "\n$(PURPLE)  Ready ✓$(NC)"

-include $(DPD)

%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -DKEY_HEADER='"$(KEY_HEADER)"' $(INC) -c $< -o $@

$(LIBFT_AR):
	@echo "\n$(PURPLE)  Compiling LIBFT...$(NC)"
	@make -s -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

clean:
	@echo "\n$(PURPLE)  Cleaning object files... $(NC)"
	@rm -rf $(OBJ)
	@rm -rf $(DPD)
	@make -s clean -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

fclean: clean
	@echo "\n$(PURPLE)  Cleaning Push_swap...$(NC)"
	@$(RM) $(NAME)
	@make -s fclean -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

re: fclean all

.PHONY: all clean fclean re
