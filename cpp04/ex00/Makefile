NAME = animal
CXX = c++
CFLGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CFLGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CFLGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
