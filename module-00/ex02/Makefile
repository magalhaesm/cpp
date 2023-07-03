NAME  := account

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

HEADERS  := Account.hpp
SRCS     := Account.cpp tests.cpp
OBJS     := $(SRCS:.cpp=.o)
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@$(LOG) "Compiling $@"

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

check: $(NAME)
	@$(LOG) "Creating log file"
	./$(NAME) > output.log
	@$(LOG) "Remove timestamps"
	cut -d ' ' -f 2 19920104_091532.log > original.log
	cut -d ' ' -f 2 output.log > testing.log
	@$(LOG) "Compare results"
	diff original.log testing.log

clean:
	@$(LOG) "Removing $(NAME)"
	@$(RM) -r $(NAME)

fclean: clean
	@$(LOG) "Removing objects"
	@$(RM) -r $(OBJS)

re: clean all

.PHONY: all, check, clean, fclean, re
