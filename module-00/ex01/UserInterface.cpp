/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:49:32 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/02 13:06:21 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterface.hpp"

std::string	UserInterface::getUserInput(const std::string &prompt)
{
	std::string	input;

	while (input.empty()) {
		std::cout << prompt;
		std::getline(std::cin, input);

		if (std::cin.eof())
		{
			showError("\nOperation canceled. End of input (EOF) detected.");
			exit(EXIT_FAILURE);
		}

		if (input.empty())
			showError("This field cannot be left empty.");

		if (input.length() > 100)
		{
			input.clear();
			showError("Field length exceeds the maximum limit of 100 characters.");
		}
	}
	return (input);
}

void	UserInterface::showMessage(const std::string &message)
{
	std::cout << message << std::endl;
}

void	UserInterface::showError(const std::string &message)
{
	std::cerr << message << std::endl;
}
