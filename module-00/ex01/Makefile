NAME  := phonebook

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

SRCS     := main.cpp PhoneBook.cpp Contact.cpp TableFormatter.cpp userInterface.cpp
HEADERS  := PhoneBook.hpp Contact.hpp TableFormatter.hpp userInterface.hpp
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
	@$(LOG) "Removing test files"

fclean: clean
	@$(LOG) "Removing $(NAME)"
	@$(RM) -r $(NAME)

re: clean all

.PHONY: all, check, clean, fclean, re
