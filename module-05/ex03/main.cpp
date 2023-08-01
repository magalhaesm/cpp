/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:12:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/31 21:05:13 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define GREEN "\033[1;32m"
#define RESET "\033[0m"

void print_title(const std::string& title);

int main()
{
    {
        print_title("Test: ShrubberyCreationForm Successfully Created");

        Intern intern;
        AForm* form;

        form = intern.makeForm("shrubbery creation", "Berder");
        std::cout << "Target: " << form->getTarget() << std::endl;

        delete form;
    }
    {
        print_title("Test: RobotomyRequestForm Successfully Created");

        Intern intern;
        AForm* form;

        form = intern.makeForm("robotomy request", "Berder");
        std::cout << "Target: " << form->getTarget() << std::endl;

        delete form;
    }
    {
        print_title("Test: RobotomyRequestForm Successfully Created");

        Intern intern;
        AForm* form;

        form = intern.makeForm("presidential pardon", "Berder");
        std::cout << "Target: " << form->getTarget() << std::endl;

        delete form;
    }
    {
        print_title("Test: Form NOT Successfully Created");

        Intern intern;
        AForm* form;

        try
        {
            form = intern.makeForm("some random form", "Berder");
            std::cout << "Target: " << form->getTarget() << std::endl;

            delete form;
        }
        catch (const Intern::FormNotFound& error)
        {
            std::cout << "Exception: " << error.what() << std::endl;
            return EXIT_SUCCESS;
        }
    }
}

void print_title(const std::string& title)
{
    std::cout << std::string(40, '-') << std::endl;
    std::cout << GREEN << "\n" << title << "\n" << RESET << std::endl;
}
