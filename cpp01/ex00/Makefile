NAME = zombie
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
FLGS = -Wall -Werror -Wextra -std=c++98 -pedantic

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(FLGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(FLGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
