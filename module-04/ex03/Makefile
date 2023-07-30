NAME := ex03

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

HEADERS  := AMateria.hpp Ice.hpp Cure.hpp Character.hpp ICharacter.hpp
HEADERS  += IMateriaSource.hpp MateriaSource.hpp
SRCS     := AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp
OBJS     := $(SRCS:.cpp=.o)
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

run: all
	@./$(NAME)

leaks: all
	@valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

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
