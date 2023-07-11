NAME  := brainz

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

HEADERS  := Zombie.hpp
SRCS     := Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJS     := $(SRCS:.cpp=.o)
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@$(LOG) "Compiling $@"

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJS)

fclean: clean
	@$(LOG) "Removing $(NAME)"
	@$(RM) -r $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
