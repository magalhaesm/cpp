NAME := convert

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

HEADERS  := ScalarConverter.hpp ConversionStrategy.hpp AConversionStrategy.hpp
SRCS     := ScalarConverter.cpp ConversionStrategy.cpp AConversionStrategy.cpp main.cpp
OBJS     := $(SRCS:.cpp=.o)
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

run: all
	@./$(NAME)

leaks: all
	@valgrind --track-origins=yes --leak-check=full ./$(NAME)

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

.PHONY: all, clean, fclean, re, leaks, run
