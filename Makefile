# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 14:13:10 by nivergne          #+#    #+#              #
#    Updated: 2019/04/15 14:13:15 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

NAME = nivergne.filler

LIBFT = -L ./libft/ -I ./libft/include -lft

LIBFTOBJ = -I ./libft/include

INCLUDE = -I ./include

SRC_PATH = ./src
INC_PATH = ./include
OBJ_PATH = ./obj

SRC_NAME =

INC_NAME = filler.h
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: logo libft $(NAME)

$(NAME): $(INC) $(OBJ)
	@$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[38;2;0;255;255mFiller\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"
	@echo "\033[38;2;0;255;255mFiller\t\033[38;2;255;0;0m$(NAME)\t\t\033[0;32m[OK]\033[0m"

libft:
	@$(MAKE) -C libft/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[38;2;0;255;0m[cc]\033[0m: $< -> $@"
	@printf "\e[1A"
	@$(CC) $(FLAGS) $(INCLUDE) $(LIBFTOBJ) -c $< -o $@
	@printf "\e[0K"

clean:
	@$(MAKE) -C libft/ clean
	@rm -rf $(OBJ)
	@echo "\033[38;2;0;255;255mFiller\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -rf ./obj $(NAME)
	@echo "\033[38;2;0;255;255mFiller\t\033[1;33mCleaning exe\t\033[0;32m[OK]\033[0m"

logo:
	@echo ""
	@echo   "\033[38;2;0;0;255m __                              _           "
	@echo  "\033[38;2;38;0;255m[  |                            (_)          "
	@echo  "\033[38;2;76;0;255m | | .---.  _ .--..--.  ______  __   _ .--.  "
	@echo "\033[38;2;114;0;255m | |/ /__\\[ \`.-. .-. ||______|[  | [ \`.-. | "
	@echo "\033[38;2;152;0;255m | || \__., | | | | | |         | |  | | | | "
	@echo "\033[38;2;191;0;255m[___]'.__.'[___||__||__]       [___][___||__]"
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re logo libft