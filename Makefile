# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 03:12:29 by bpouchep          #+#    #+#              #
#    Updated: 2022/07/27 03:12:33 by bpouchep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	ft_containers
NAME_S_FT		=	ft_stack_test
NAME_S_STD		=	std_stack_test
NAME_V_FT		=	ft_vector_test
NAME_V_STD		=	std_vector_test
NAME_M_FT		=	ft_map_test
NAME_M_STD		=	std_map_test

SRCS 			=	main.cpp
TEST_MAP_FT		=	main_map_ft.cpp
TEST_MAP_STD	=	main_map_std.cpp
TEST_STACK_FT	=	main_stack_ft.cpp
TEST_STACK_STD	=	main_stack_std.cpp
TEST_VECTOR_FT	=	main_vector_ft.cpp
TEST_VECTOR_STD	=	main_vector_std.cpp

OBJS			=		$(SRCS:.cpp=.o)
DEPS			=		$(SRCS:.cpp=.d)
OBJS_STACK_FT	=		$(TEST_STACK_FT:.cpp=.o)
DEPS_STACK_FT	=		$(TEST_STACK_FT:.cpp=.d)
OBJS_STACK_STD	=		$(TEST_STACK_STD:.cpp=.o)
DEPS_STACK_STD	=		$(TEST_STACK_STD:.cpp=.d)
OBJS_VECTOR_FT	=		$(TEST_VECTOR_FT:.cpp=.o)
DEPS_VECTOR_FT	=		$(TEST_VECTOR_FT:.cpp=.d)
OBJS_VECTOR_STD	=		$(TEST_VECTOR_STD:.cpp=.o)
DEPS_VECTOR_STD	=		$(TEST_VECTOR_STD:.cpp=.d)
OBJS_MAP_FT		=		$(TEST_MAP_FT:.cpp=.o)
DEPS_MAP_FT		=		$(TEST_MAP_FT:.cpp=.d)
OBJS_MAP_STD	=		$(TEST_MAP_STD:.cpp=.o)
DEPS_MAP_STD	=		$(TEST_MAP_STD:.cpp=.d)

INCLUDE		= 		include
RM			=		rm -f
CC			=		c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3

%.o:				%.cpp
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCLUDE)

all:	$(NAME) stack vector map

stack:	$(NAME_S_FT) $(NAME_S_STD)

vector: $(NAME_V_FT) $(NAME_V_STD)

map:	$(NAME_M_FT) $(NAME_M_STD)

$(NAME_S_FT):		$(OBJS_STACK_FT) $(OBJS_STACK_STD)
	$(CC) $(CFLAGS) $(OBJS_STACK_FT) -o $(NAME_S_FT)
	$(CC) $(CFLAGS) $(OBJS_STACK_STD) -o $(NAME_S_STD)
	./$(NAME_S_FT) > ft_stack
	./$(NAME_S_STD) > std_stack

$(NAME_V_FT):		$(OBJS_VECTOR_FT) $(OBJS_VECTOR_STD)
	$(CC) $(CFLAGS) $(OBJS_VECTOR_FT) -o $(NAME_V_FT)
	$(CC) $(CFLAGS) $(OBJS_VECTOR_STD) -o $(NAME_V_STD)
	./$(NAME_V_FT) > ft_vector
	./$(NAME_V_STD) > std_vector

$(NAME_M_FT):		$(OBJS_MAP_FT) $(OBJS_MAP_STD)
	$(CC) $(CFLAGS) $(OBJS_MAP_FT) -o $(NAME_M_FT)
	$(CC) $(CFLAGS) $(OBJS_MAP_STD) -o $(NAME_M_STD)
	./$(NAME_M_FT) > ft_map
	./$(NAME_M_STD) > std_map

$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(DEPS) $(OBJS_STACK_FT) $(OBJS_STACK_STD) $(DEPS_STACK_FT) $(DEPS_STACK_STD)
	@$(RM) $(OBJS_VECTOR_FT) $(OBJS_VECTOR_STD) $(DEPS_VECTOR_FT) $(DEPS_VECTOR_STD)
	@$(RM) $(OBJS_MAP_FT) $(OBJS_MAP_STD) $(DEPS_MAP_FT) $(DEPS_MAP_STD)
fclean: clean
	@$(RM) $(NAME) $(NAME_S_FT) $(NAME_S_STD) $(NAME_V_FT) $(NAME_V_STD) $(NAME_M_FT) $(NAME_M_STD)
	@$(RM) ft_map ft_vector ft_stack std_map std_vector std_stack

re:		fclean all

-include $(DEPS) $(DEPS_STACK_FT) $(DEPS_STACK_STD) $(DEPS_VECTOR_FT) $(DEPS_VECTOR_STD) $(DEPS_MAP_FT) $(DEPS_MAP_STD)
.PHONY: all clean fclean re stack vector map