NAME := unnecessary-violence

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

HEADERS  := Weapon.hpp HumanA.hpp HumanB.hpp
SRCS     := Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
OBJS     := $(SRCS:.cpp=.o)
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

run: all
	@./$(NAME)

leaks: all
	@valgrind --track-origins=yes --leak-check=full ./$(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Compiling $@"
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJS)

fclean: clean
	@$(LOG) "Removing $(NAME)"
	@$(RM) -r $(NAME)

re: clean all

.PHONY: all clean fclean re leaks run
