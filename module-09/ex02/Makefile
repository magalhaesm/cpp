NAME := PmergeMe

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

HEADERS  := PmergeMe.hpp
SRCS     := PmergeMe.cpp main.cpp
OBJS     := $(SRCS:.cpp=.o)
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

TEST_LIB := doctest.h

all: $(NAME)

gdb: $(NAME)
	@gdb -x debug.gdb --args ./$(NAME) "7 8 27 100 11 46 2 53 0"

run: all
	@./$(NAME) "7 8 27 100 11 46 2 53 0"

$(TEST_LIB):
	@$(LOG) "Getting test framework"
	@wget -q https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h

tests: $(TEST_LIB)
	@$(LOG) "Compiling test suite"
	@$(CXX) tests.cpp -o tests
	@./tests -ltc

leaks: all
	@valgrind --track-origins=yes --leak-check=full ./$(NAME) input.txt

$(NAME): $(OBJS)
	@$(LOG) "Compiling $@"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJS)

fclean: clean
	@$(LOG) "Removing $(NAME)"
	@$(RM) -r $(NAME)

re: clean all

.PHONY: all clean fclean re leaks run tests
