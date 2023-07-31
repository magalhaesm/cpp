/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:12:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/31 17:39:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define FAIL "\033[1;7;31mFAIL\033[0m"

void print_title(const std::string& title);

int main()
{
    {
        print_title("Test: ShrubberyCreationForm Successfully Executed");

        Bureaucrat bob("Bob", 137);
        std::cout << bob << std::endl;

        ShrubberyCreationForm form("home");

        bob.signForm(form);
        bob.executeForm(form);

        std::cout << '\n' << form << std::endl;
    }
    {
        print_title("Test: ShrubberyCreationForm Not Successfully Executed");

        Bureaucrat bob("Bob", 145);
        std::cout << bob << std::endl;

        ShrubberyCreationForm form("home");

        bob.signForm(form);
        bob.executeForm(form);

        std::cout << '\n' << form << std::endl;
    }
    {
        print_title("Test: RobotomyRequestForm Successfully Executed");

        Bureaucrat bob("Bob", 45);
        std::cout << bob << std::endl;

        RobotomyRequestForm form("home");

        bob.signForm(form);
        bob.executeForm(form);

        std::cout << '\n' << form << std::endl;
    }
    {
        print_title("Test: RobotomyRequestForm Not Successfully Executed");

        Bureaucrat bob("Bob", 72);
        std::cout << bob << std::endl;

        RobotomyRequestForm form("home");

        bob.signForm(form);
        bob.executeForm(form);

        std::cout << '\n' << form << std::endl;
    }
    {
        print_title("Test: PresidentialPardonForm Successfully Executed");

        Bureaucrat bob("Bob", 5);
        std::cout << bob << std::endl;

        PresidentialPardonForm form("home");

        bob.signForm(form);
        bob.executeForm(form);

        std::cout << '\n' << form << std::endl;
    }
    {
        print_title("Test: PresidentialPardonForm Not Successfully Executed");

        Bureaucrat bob("Bob", 25);
        std::cout << bob << std::endl;

        PresidentialPardonForm form("home");

        bob.signForm(form);
        bob.executeForm(form);

        std::cout << '\n' << form << std::endl;
    }
    {
        print_title("Test: Form Copy Constructor");

        ShrubberyCreationForm formA("home");
        ShrubberyCreationForm formB(formA);

        std::cout << formB << std::endl;
        std::cout << "Target: " << formB.getTarget() << '\n' << std::endl;

        RobotomyRequestForm formC("Bob");
        RobotomyRequestForm formD(formC);

        std::cout << formD << std::endl;
        std::cout << "Target: " << formD.getTarget() << '\n' << std::endl;

        PresidentialPardonForm formE("Saul");
        PresidentialPardonForm formF(formE);

        std::cout << formF << std::endl;
        std::cout << "Target: " << formF.getTarget() << std::endl;
    }
}

void print_title(const std::string& title)
{
    std::cout << std::string(40, '-') << std::endl;
    std::cout << GREEN << "\n" << title << "\n" << RESET << std::endl;
}
