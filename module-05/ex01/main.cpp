/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:12:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 17:40:41 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define FAIL "\033[1;7;31mFAIL\033[0m"

void print_title(const std::string& title);
void print_failure();

int main()
{
    {
        print_title("Test: Exception is Thrown for Grade Above Maximum in Constructor");

        try
        {
            Form form("Default", 0);
            print_failure();
        }
        catch (const std::exception& error)
        {
            std::cout << error.what() << std::endl;
        }
    }
    {
        print_title("Test: Exception is Thrown for Grade Below Minimum in Constructor");

        try
        {
            Form form("Default", 151);
            print_failure();
        }
        catch (const std::exception& error)
        {
            std::cout << error.what() << std::endl;
        }
    }
    {
        print_title("Test: Form Successfully Signed");

        Bureaucrat bob("Bob", 60);
        Form form("Travel Request", 80);

        std::cout << bob << std::endl;
        bob.signForm(form);
        std::cout << '\n' << form << std::endl;
    }
    {
        print_title("Test: Form Not Successfully Signed");

        Bureaucrat bob("Bob", 90);
        Form form("Travel Request", 80);

        try
        {
            std::cout << bob << std::endl;
            bob.signForm(form);
            std::cout << '\n' << form << std::endl;
        }
        catch (const std::exception& error)
        {
            std::cout << error.what() << std::endl;
        }
    }
}

void print_title(const std::string& title)
{
    std::cout << std::string(40, '-') << std::endl;
    std::cout << GREEN << "\n" << title << "\n" << RESET << std::endl;
}

void print_failure()
{
    std::cout << FAIL << std::endl;
}
