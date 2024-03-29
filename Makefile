# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 08:49:56 by cpierce           #+#    #+#              #
#    Updated: 2019/11/26 21:52:31 by cpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = a_flag.c l_flag.c l_flag2.c makestr.c merge_sort.c output.c r_flag.c t_flag.c adddir.c

OBJS = a_flag.o l_flag.o l_flag2.o makestr.o merge_sort.o output.o r_flag.o t_flag.o adddir.o

.PHONY:
	clean fclean re

all: $(NAME)

$(NAME): 
	@gcc -c $(SRCS) libft/libft.a
	@gcc main.c $(OBJS) libft/libft.a

g:
	@gcc -c -g $(SRCS) libft/libft.a
	@gcc -g main.c $(OBJS) libft/libft.a

sanitize:
	@gcc -c -g -fsanitize=address $(SRCS) libft/libft.a
	@gcc -g -fsanitize=address main.c $(OBJS) libft/libft.a

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
