# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 14:13:10 by nivergne          #+#    #+#              #
#    Updated: 2019/04/18 23:20:45 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nivergne.filler

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

LIBFT = -L ./libft/ -I ./libft/include -lft
LIBFTOBJ = -I ./libft/include

INCLUDE = -I ./include

SRC_PATH = 	./src
INC_PATH = 	./include
OBJ_PATH = 	./obj

SRC_FILLER =				main.c\
							map.c\
							filler.c

UNDER	=					\x1b[4m
BOLD	=					\x1b[1m
REV		=					\x1b[7m
END		=					\x1b[0m

RED		=					\x1b[31m
GREEN	=					\x1b[32m
BLUE	=					\x1b[34m
YELLOW	=					\x1b[33m
CYAN	=					\x1b[36m
PURPLE	=					\x1b[35m
GREY	=					\x1b[40m
WHITE	=					\x1b[37m

IRED	=					\x1b[41m
IGREEN	=					\x1b[42m
IBLUE	=					\x1b[44m
IYELLOW	=					\x1b[43m
ICYAN	=					\x1b[46m
IPURPLE	=					\x1b[45m
IGREY	=					\x1b[40m
IWHITE	=					\x1b[47m

DARK_PURPLE		=			\033[38;2;65;0;255m
DARK_PINK		= 			\033[38;2;86;0;255m
PURPLE			=			\033[38;2;114;0;255m
PINK			=			\033[38;2;152;0;255m

INC_NAME = 	filler.h
OBJ_NAME = $(SRC_FILLER:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILLER))
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
	@echo "$(BOLD)$(CYAN)FILLER$(BLUE)			obj		$(END)$(RED)[delete]$(END)"

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -rf ./obj $(NAME)
	@echo "$(BOLD)$(CYAN)FILLER$(BLUE)			archive		$(END)$(RED)[delete]$(END)"

logo:
	@echo "$(DARK_PURPLE)  /000000  /00 /00 /00                    "
	@echo "$(DARK_PURPLE) /00__  00|__/| 00| 00                    "
	@echo "$(DARK_PINK)| 00  \__/ /00| 00| 00  /000000   /000000 "
	@echo "$(DARK_PINK)| 0000    | 00| 00| 00 /00__  00 /00__  00"
	@echo "$(PURPLE)| 00_/    | 00| 00| 00| 00000000| 00  \__/"
	@echo "$(PURPLE)| 00      | 00| 00| 00| 00_____/| 00      "
	@echo "$(PINK)| 00      | 00| 00| 00|  0000000| 00      "
	@echo "$(PINK)|__/      |__/|__/|__/ \_______/|__/      "
	@echo "$(END)"

re: fclean all

.PHONY: all clean fclean re logo libft