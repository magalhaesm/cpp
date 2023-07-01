/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:34:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/01 11:46:21 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	toString(size_t nbr);

PhoneBook::PhoneBook()
{
	numContacts = 0;
}

void	PhoneBook::addContact()
{
	Contact newContact;

	ui.display("Add new contact:");
	try {
		newContact.setFirstName(getText("First name: "));
		newContact.setLastName(getText("Last name: "));
		newContact.setNickName(getText("Nickname: "));
		newContact.setPhoneNumber(getNumber("Phone number: "));
		newContact.setDarkestSecret(ui.getUserInput("Darkest secret: "));
	} catch (const std::runtime_error &err) {
		ui.log(err.what());
		return ;
	}
	addToContacts(newContact);
	ui.display("Contact added!");
}

void	PhoneBook::addToContacts(const Contact &contact)
{
	contacts[numContacts % CAPACITY] = contact;
	numContacts++;
}

void	PhoneBook::searchContact()
{
	ui.display(createContactTable());
}

static std::string	toString(size_t nbr)
{
	std::ostringstream oss;

	oss << nbr;
	return oss.str();
}

size_t PhoneBook::calculateStartIndex(void)
{
	return (numContacts > CAPACITY) ? numContacts % CAPACITY : 0;
}

std::string	PhoneBook::createContactTable(void)
{
	size_t		idx;
	std::string	table;

	formatter.appendField("Index");
	formatter.appendField("First Name");
	formatter.appendField("Last Name");
	formatter.appendField("Nick Name");
	table = formatter.createTableHeader();

	for (size_t i = calculateStartIndex(); i < numContacts; i++) {
		idx = i % CAPACITY;
		formatter.appendField(toString(idx));
		formatter.appendField(contacts[idx].getFirstName());
		formatter.appendField(contacts[idx].getLastName());
		formatter.appendField(contacts[idx].getNickName());
		table += formatter.createTableRow();
	}

	return table;
}

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
