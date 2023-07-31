/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:12:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/31 09:37:04 by mdias-ma         ###   ########.fr       */
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
    Bureaucrat marcelo("Marcelo", 81);
    Form form("SomeForm", 80);

    marcelo.signForm(form);
    std::cout << form << std::endl;
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
