# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:53:40 by mobouzar          #+#    #+#              #
#    Updated: 2019/09/19 16:25:50 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
OBJECTS = ft_print_d.o ft_get_flag.o ft_padding.o  ft_print_d.o  ft_printf.o  \
			ft_print_base.o ft_print_char.o helper.o ft_print_f.o ft_float.o ft_operation.o \
			ft_float2.o
			
LIBFT = libft/libft.a
INCLUDE = .

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(INCLUDE)/ft_printf.h
		@ar rc $(NAME) $(OBJECTS) libft/*.o
		@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"
		@echo "\033[0;32m| >>>>>>>>>>>>>>>>>>>>>>>>>> Compiled Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
		@echo "\033[0;32m-------------------------------------------------------------------------------\033[0m"

%.o : %.c
		@gcc $(FLAGS) -g -c $< -o $@
$(LIBFT):
		@make -C libft/
clean : 
		@make clean -C libft/
		@rm -f $(OBJECTS)
		@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"
		@echo "\033[1;33m| >>>>>>>>>>>>>>>>>>>>>>>>>>  Cleaned Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
		@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"

fclean : clean
		@make fclean -C libft/
		@rm -f $(NAME)

re : fclean all
