
NAME = push_swap
NAME_BON = checker

SRC_PATH = srcs/
BON_PATH = srcs_bonus/
LIBFT_PATH = libft/
LIBFT_AR = $(LIBFT_PATH)libft.a

SRC = push_swap.c parsing.c stack_push.c stack_rotate.c stack_revrotate.c \
	  stack_swap.c stack_utils.c divide.c conquer.c split_from_to.c \
	  three_sort.c opti_utils.c max_and_min.c general_utils.c main.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
DPD = $(SRC:.c=.d)

BONU = checker.c general_utils.c parsing.c stack_push.c stack_rotate.c \
	   stack_revrotate.c stack_swap.c stack_utils.c push_swap.c
BONUS = $(addprefix $(BON_PATH), $(BONU))
OBJ_BON = $(BONUS:.c=.o)
OBJ_DPD = $(BONUS:.c=.d)

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
	@echo "\n$(PURPLE)  Ready ✓$(NC)\n"

-include $(DPD)

bonus: $(OBJ_BON) $(INCS)
	@echo "\n$(PURPLE)  Compiling Bonus...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ_BON) $(LIBFT_AR) $(INC) -o $(NAME_BON)
	@echo "\n$(PURPLE)  Ready ✓$(NC)\n"

-include $(OBJ_DPD)

%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_AR):
	@echo "\n$(PURPLE)  Compiling LIBFT...$(NC)"
	@make -s -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

clean:
	@echo "\n$(PURPLE)  Cleaning object files... $(NC)"
	@rm -rf $(OBJ) $(OBJ_BON)
	@rm -rf $(DPD) $(OBJ_DPD)
	@make -s clean -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

fclean: clean
	@echo "\n$(PURPLE)  Cleaning Push_swap...$(NC)"
	@$(RM) $(NAME)
	@$(RM) $(NAME_BON)
	@make -s fclean -C $(LIBFT_PATH)
	@echo "\n$(PURPLE)  Done ✓$(NC)"

re: fclean all

.PHONY: all clean fclean re
