NAME = harl
CXX = c++
FLGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)

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