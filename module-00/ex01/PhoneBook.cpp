/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:34:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/28 14:58:22 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contactIndex = 0;
}

void	PhoneBook::addContact()
{
	ui.showMessage("Add new contact:");
	try {
		validationContact.setFirstName(ui.getUserInput("First name: "));
		validationContact.setLastName(ui.getUserInput("Last name: "));
		validationContact.setNickName(ui.getUserInput("Nickname: "));
		validationContact.setPhoneNumber(ui.getUserInput("Phone number: "));
		validationContact.setDarkestSecret(ui.getUserInput("Darkest secret: "));
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	contacts[contactIndex] = validationContact;
	contactIndex++;
}

void	PhoneBook::searchContact()
{

}

void	PhoneBook::exit()
{

}
