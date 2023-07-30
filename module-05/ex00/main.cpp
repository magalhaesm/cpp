/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:12:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/30 19:01:14 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define FAIL "\033[1;7;31mFAIL\033[0m"

void print_title(const std::string& title);
void print_failure();

int main()
{
    {
        print_title("Test Constructor/Assignment");

        Bureaucrat a("Bob", 42);
        Bureaucrat b = a;
        Bureaucrat c(a);

        std::cout << "A: " << a << std::endl;
        std::cout << "B: " << b << std::endl;
        std::cout << "C: " << c << std::endl;
    }
    {
        print_title("Test Increment/Decrement");

        Bureaucrat test("Bob", 42);
        std::cout << test << std::endl;

        test.incrementGrade();
        std::cout << test << std::endl;

        test.decrementGrade();
        std::cout << test << std::endl;
    }
    {
        print_title("Test: Exception is Thrown for Grade Above Maximum in Constructor");
        try
        {
            Bureaucrat test("Bob", 0);
            print_failure();
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        print_title("Test: Exception is Thrown for Grade Below Minimum in Constructor");
        try
        {
            Bureaucrat test("Bob", 151);
            print_failure();
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        print_title("Test: Exception is Thrown for Incrementing Grade Above Maximum");

        Bureaucrat test("Bob", 1);

        std::cout << test << std::endl;
        try
        {
            test.incrementGrade();
            print_failure();
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        print_title("Test: Exception is Thrown for Decrementing Grade Below Minimum");

        Bureaucrat test("Bob", 150);

        std::cout << test << std::endl;
        try
        {
            test.decrementGrade();
            print_failure();
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
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
