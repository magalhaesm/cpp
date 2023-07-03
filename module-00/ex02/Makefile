NAME  := account

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

SRCS     := Account.cpp tests.cpp
HEADERS  := Account.hpp
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

.PHONY: all
all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@$(LOG) "Building $@"

.PHONY: clean
clean:
	@$(LOG) "Removing $(NAME)"
	@$(RM) -r $(NAME)

.PHONY: fclean
fclean: clean
	@$(LOG) "Cleaning $(BUILD_DIR)"
	@$(RM) -r $(BUILD_DIR)

.PHONY: re
re: clean all
