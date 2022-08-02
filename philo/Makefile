# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbuccher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 18:25:54 by lbuccher          #+#    #+#              #
#    Updated: 2022/03/04 18:25:55 by lbuccher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c\
		init_philosopher.c\
		philo_utils.c\
		ft_atoi.c\
		ft_isdigit.c

OBJ = $(SRCS:.c=.o)

INCLUDE = philo.h

FLAGS = -Wall -Werror -Wextra -pthread

CC = gcc

.c.o:
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
