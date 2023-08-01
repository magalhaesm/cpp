NAME := ex03

RESET := \033[0m
CYAN  := \033[36m
CHECK := \342\234\224
LOG   := printf "[$(CYAN)$(CHECK)$(RESET)] %s\n"

HEADERS  := Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp Intern.hpp
HEADERS  += RobotomyRequestForm.hpp PresidentialPardonForm.hpp
SRCS     := Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp Intern.cpp
SRCS     += RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp
OBJS     := $(SRCS:.cpp=.o)
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

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

.PHONY: all, clean, fclean, re
