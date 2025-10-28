# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 14:24:40 by lmatthes          #+#    #+#              #
#    Updated: 2025/10/28 13:44:01 by lmatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  	= libft.a
CC		= cc 
CFLAGS	= -Wall -Wextra -Werror
AR 		= ar rcs
RM 		= rm -f

PART1 	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
		ft_strdup.c 

PART2	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

SRC 	= $(PART1) $(PART2)

OBJ		= $(SRC:.c=.o)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "$< compiled!"

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)
		@echo "$(NAME) created!"

all:	$(NAME)

clean:
		@$(RM) $(OBJ)
		@echo "Object files removed!"

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(NAME) removed!"

re: fclean all