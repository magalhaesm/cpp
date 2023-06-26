NAME  := megaphone

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

SRC      := megaphone.cpp
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

.PHONY: all
all: $(NAME)

$(NAME): $(SRC)
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
