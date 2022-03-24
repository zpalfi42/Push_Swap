# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:16:53 by zpalfi            #+#    #+#              #
#    Updated: 2022/03/24 16:00:08 by zpalfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

#--------------- DIRS ---------------#

INCLUDE_DIR	= include
SRC_DIR		= src
LIBS_DIR	= libs
OBJS_DIR	= objs

#--------------- FILES ---------------#

LIBS			= $(LIBS_DIR)/Libft/libft.a \

LIBS_HEADERS	= -I $(LIBS_DIR)/Libft/include/ \

INC				= -I $(INCLUDE_DIR) $(LIBS_HEADERS)

SRC				= pa.c \
				  pb.c \
				  error.c \
				  push_swap.c \
				  solve_med.c \
				  solve_hard.c \
				  solve_easy.c \
				  init_check.c \
				  rr_comands.c \
				  rrr_comands.c \
				  swap_comands.c \
				  solve_med_utils.c \
				  solve_hard_utils.c \
				  solve_hard_utils_2.c \

OBJ				= $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))

#--------------- COMPILATION ---------------#

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g $(INC)

#--------------- RULES ---------------#

objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "Compiling $^"

all:	$(NAME)

$(NAME): $(OBJ) $(LIBS)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Built $(NAME)"

$(LIBS_DIR)/Libft/libft.a:
	@make -C $(LIBS_DIR)/Libft

clean:
	@rm -rf $(OBJS_DIR)

fclean:	clean
	@make fclean -C $(LIBS_DIR)/Libft
	@rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean
