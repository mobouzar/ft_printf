# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 19:42:06 by mobouzar          #+#    #+#              #
#    Updated: 2019/09/17 18:48:06 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -Wall -Wextra  -Werror
OBJECTS = 	ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_itoa_base.o \
		ft_strcpy.o ft_char_nbr.o ft_strncpy.o ft_strcat.o ft_memccpy.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o \
		ft_strnstr.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_str_toupper.o ft_isalnum.o ft_isascii.o \
		ft_isprint.o ft_toupper.o ft_safe.o ft_tolower.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o \
		ft_striter.o ft_strnew_00.o ft_str_nbr.o ft_striteri.o ft_strjoin_free.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o \
		ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o \
		ft_putstr_fd.o ft_strjoin_00.o ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o \
		ft_lstmap.o ft_abs.o ft_swap.o ft_strrev.o ft_getcharindex.o ft_lstdisplcont.o ft_lstendadd.o ft_lstsupp.o ft_sqrt.o \

all: $(NAME)

$(NAME): $(OBJECTS) ./libft.h
	@ar rc $(NAME) $(OBJECTS)
%.o : %.c
		@$(CC) -g -c $< -o $@

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
