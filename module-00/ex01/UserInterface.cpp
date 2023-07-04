/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:49:32 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/04 11:38:36 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterface.hpp"

#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[m"

std::string	UserInterface::getUserInput(const std::string &prompt)
{
	std::string	input;

	while (input.empty()) {
		std::cout << prompt;
		std::getline(std::cin, input);

		if (std::cin.eof())
		{
			displayError("\nOperation canceled. End of input (EOF) detected.");
			exit(EXIT_FAILURE);
		}

		if (input.empty())
			displayError("This field cannot be left empty.");

		if (input.length() > 100)
		{
			input.clear();
			displayError("Field length exceeds the maximum limit of 100 characters.");
		}
	}
	return (input);
}

void	UserInterface::display(const std::string &message)
{
	std::cout << message << std::endl;
}

void	UserInterface::displayInfo(const std::string &message)
{
	std::cout << GREEN << message << RESET << std::endl;
}

void	UserInterface::displayWarning(const std::string &message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

void	UserInterface::displayError(const std::string &message)
{
	std::cout << RED << message << RESET << std::endl;
}
