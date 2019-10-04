# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mydevice <mydevice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 16:53:40 by mobouzar          #+#    #+#              #
#    Updated: 2019/10/04 14:57:42 by mydevice         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
OBJECTS = srcs/ft_print_d.o srcs/ft_get_flag.o srcs/ft_padding.o srcs/ft_print_d.o srcs/ft_printf.o  \
			srcs/ft_print_base.o srcs/ft_print_char.o srcs/helper.o srcs/ft_print_f.o srcs/ft_float.o \
			srcs/ft_operation.o srcs/ft_float2.o
			
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
		@rm -rf $(OBJECTS)
		@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"
		@echo "\033[1;33m| >>>>>>>>>>>>>>>>>>>>>>>>>>  Cleaned Successfully <<<<<<<<<<<<<<<<<<<<<<<<<< |\033[0m"
		@echo "\033[1;33m-------------------------------------------------------------------------------\033[0m"

fclean : clean
		@make fclean -C libft/
		@rm -f $(NAME)

re : fclean all
