NAME := replace

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

HEADERS  := replace.hpp
SRCS     := main.cpp replace.cpp
OBJS     := $(SRCS:.cpp=.o)
TESTS    := $(filter-out main.o, $(OBJS))
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

tests: all
	@$(CXX) $(CXXFLAGS) tests.cpp $(TESTS) -o tests
	@./tests

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

.PHONY: all, clean, fclean, re, tests
