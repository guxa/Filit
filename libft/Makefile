# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 16:52:43 by jguleski          #+#    #+#              #
#    Updated: 2018/11/08 22:02:30 by jguleski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

BLIBFT = libft_funcs/
FLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c \
	  ft_strtolower.c ft_strrev.c ft_sortlist.c \
	  ft_lstmap.c ft_lstadd.c ft_lstiter.c ft_lstnew.c  \
	  ft_lstdel.c ft_lstdelone.c ft_strequ.c ft_strnequ.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
	  ft_strtrim.c ft_putendl.c ft_memalloc.c ft_strdel.c ft_strclr.c \
	  ft_strsub.c ft_strsplit.c ft_strncmp.c ft_strnstr.c \
	  ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isprint.c \
	  ft_strrchr.c ft_strlcat.c ft_strncat.c \
	  ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c \
	  ft_memcpy.c ft_bzero.c \
	  ft_putnbr.c \
	  ft_strstr.c \
	  ft_strjoin.c \
	  ft_atoi.c \
	  ft_strcat.c \
	  ft_putstr.c \
	  ft_putchar.c \
	  ft_strnew.c \
	  ft_itoa.c ft_isdigit.c ft_memset.c ft_strchr.c \
	  ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c \
	  ft_strncpy.c ft_tolower.c ft_toupper.c \
	  ft_memdel.c \
	  b_printf.c bprintf_parser.c findarg.c \

HEADER = libft.h
OBJECTS_DIR = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC))
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))
# OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJECTS_DIR) $(OBJECTS)
		@ar rc $(NAME) $(OBJECTS)
		@ranlib $(NAME)
		@echo "your lib is ready"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : %.c
	@gcc $(FLAGS) -Iincludes/ -c $< -o $@

debug:
		# gcc -Wall -Wextra -Werror -g -o test $(SRC) -Iincludes/

clean:
		@rm -rf $(OBJECTS_DIR)
		@echo "Object files and objects directory deleted"

fclean:	clean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re: fclean all
