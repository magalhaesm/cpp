/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:49:32 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/30 22:36:40 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInterface.hpp"

void	UserInterface::display(const std::string &message)
{
	std::cout << message << std::endl;
}

void	UserInterface::log(const std::string &message)
{
	std::cerr << message << std::endl;
}

std::string	UserInterface::getUserInput(const std::string &prompt)
{
	std::string	input;

	while (input.empty()) {
		std::cout << prompt;
		std::getline(std::cin, input);

		if (std::cin.eof())
			throw std::runtime_error("\nOperation canceled. End of input (EOF) detected.");

		if (input.empty())
			log("This field cannot be left empty.");
	}
	return (input);
}
