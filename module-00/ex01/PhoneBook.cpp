/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:34:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/30 22:29:42 by mdias-ma         ###   ########.fr       */
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
		validationContact.setFirstName(getText("First name: "));
		validationContact.setLastName(getText("Last name: "));
		validationContact.setNickName(getText("Nickname: "));
		validationContact.setPhoneNumber(getNumber("Phone number: "));
		validationContact.setDarkestSecret(ui.getUserInput("Darkest secret: "));
	} catch (const std::runtime_error &err) {
		ui.log(err.what());
		return ;
	}
	contacts[contactIndex] = validationContact;
	contactIndex++;
	ui.showMessage("Contact added!");
}

void	PhoneBook::searchContact()
{
	formatter.appendField("Index");
	formatter.appendField("First Name");
	formatter.appendField("Last Name");
	formatter.appendField("Nick Name");
	ui.showMessage(formatter.createTableHeader());
	formatter.appendField("0");
	formatter.appendField(contacts[0].getFirstName());
	formatter.appendField(contacts[0].getLastName());
	formatter.appendField(contacts[0].getNickName());
	ui.showMessage(formatter.createTableRow());
}

// TODO: criar função next que retorna o próximo contato

std::string	PhoneBook::getText(const std::string &prompt)
{
	bool		valid;
	std::string	name;

	do {
		name = ui.getUserInput(prompt);
		valid = validateName(name);
	} while (!valid);

	return (name);
}

std::string	PhoneBook::getNumber(const std::string &prompt)
{
	bool		valid;
	std::string	number;

	do {
		number = ui.getUserInput(prompt);
		valid = validateNumber(number);
	} while (!valid);

	return (number);
}

bool	PhoneBook::validateName(const std::string &name)
{
	if (!isAlphabetic(name)) {
		ui.log("Only letters are expected.");
		return (false);
	}
	return (true);
}

bool	PhoneBook::isAlphabetic(const std::string &str)
{
	size_t	length = str.length();

	for (size_t i = 0; i < length; i++) {
		if (!std::isalpha(str[i]))
			return (false);
	}
	return (true);
}

bool	PhoneBook::validateNumber(const std::string &str)
{
	if (!isNumeric(str)) {
		ui.log("Only numbers are expected.");
		return (false);
	}
	if (str.length() > 14) {
		ui.log("Input is too long. Please provide a shorter number.");
		return (false);
	}
	return (true);
}

bool	PhoneBook::isNumeric(const std::string &str)
{
	size_t	length = str.length();

	for (size_t i = 0; i < length; i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}
