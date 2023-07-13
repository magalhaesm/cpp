NAME := hi-this-is-brain

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

SRCS     := main.cpp
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

run: all
	@./$(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(CXXFLAGS) $< -o $@
	@$(LOG) "Compiling $@"

clean:
	@$(LOG) "Removing $(NAME)"
	@$(RM) -r $(NAME)

fclean: clean

re: clean all

.PHONY: all, clean, fclean, re
