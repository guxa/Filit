# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 16:52:43 by jguleski          #+#    #+#              #
#    Updated: 2018/11/08 22:09:29 by jguleski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit
LIBFT = libft
FLAGS = -Wall -Wextra -Werror

LIB = $(LIBFT)/libft.a

SRC = fillit.c gameplay.c \
	  filist.c final_solution.c ft_sqrt.c parser.c

INCLUDES = -I. -I$(LIBFT)/includes/

OBJECTS_DIR = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC))
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

all: $(NAME)

$(NAME): $(LIB) $(OBJECTS_DIR) $(OBJECTS)
	 gcc $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIB) -o $(NAME)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@echo "Directory objects was created"

$(OBJECTS_DIR)%.o : %.c
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIB):
		@make -C $(LIBFT)

debug: $(SRC) $(LIB)
		gcc $(FLAGS) -g $(INCLUDES) $(SRC) $(LIB) -o test-$(NAME)

clean:
		make -C $(LIBFT) clean
		@rm -rf $(OBJECTS_DIR)

fclean:	clean
		rm -f $(NAME)
		@make -C $(LIBFT) fclean

re: fclean all
