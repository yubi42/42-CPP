# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jborner <jborner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 09:20:26 by yubi42            #+#    #+#              #
#    Updated: 2024/03/08 13:25:56 by jborner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = replace.out

ADDITION = new_file

SRCS =	main.cpp \

OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))

all: $(NAME)

$(OBJ_PATH)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ_PATH) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(ADDITION) 

re: fclean all

.PHONY: all clean fclean re