# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 09:20:26 by yubi42            #+#    #+#              #
#    Updated: 2024/10/29 09:49:13 by yubi42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -I. # -g -Ofast

NAME = PmergeMe

SRCS =	main.cpp \
		PmergeMe.cpp
	
OBJ_PATH = .obj/
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
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re