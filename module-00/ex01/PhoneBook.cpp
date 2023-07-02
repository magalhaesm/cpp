/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:34:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/02 13:02:52 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	toString(size_t nbr);

PhoneBook::PhoneBook(UserInterface &userInterface)
{
	numContacts = 0;
	ui = userInterface;
}

void	PhoneBook::addContact()
{
	Contact	newContact;

	ui.showMessage("\n[+] Add new contact:");
	newContact.setFirstName(getText("First name: "));
	newContact.setLastName(getText("Last name: "));
	newContact.setNickname(getText("Nickname: "));
	newContact.setPhoneNumber(getNumber("Phone number: "));
	newContact.setDarkestSecret(ui.getUserInput("Darkest secret: "));

	addToContacts(newContact);
	ui.showMessage("New contact has been added!");
}

void	PhoneBook::addToContacts(const Contact &contact)
{
	static size_t	index;

	contacts[index % CAPACITY] = contact;
	index++;
	numContacts = (index < CAPACITY) ? index : CAPACITY;
}

void	PhoneBook::searchContact()
{
	std::string	number;
	size_t		index;

	if (!numContacts)
	{
		ui.showError("\nThe phonebook is currently empty.");
		return ;
	}

	ui.showMessage(createContactTable());
	do {
		number = getNumber("[+] Please choose an index to display: ");
		index = std::atoi(number.c_str());

		if (index > numContacts)
			ui.showError("Invalid index. Please choose one within the range.");
	} while (index > numContacts);

	ui.showMessage(getContactDetail(contacts[index]));
}

std::string	PhoneBook::getContactDetail(Contact &contact)
{
	std::string	details;
	std::string	separator(45, '*');

	details += "\n" + separator + "\n";
	details += "Contact Details:\n";
	details += "- First Name: " + contact.getFirstName() + '\n';
	details += "- Last Name: " + contact.getLastName() + '\n';
	details += "- Nickname: " + contact.getNickname() + '\n';
	details += "- Phone Number: " + contact.getPhoneNumber() + '\n';
	details += "- Darkest Secret: " + contact.getDarkestSecret() + '\n';
	details += separator;

	return details;
}

static std::string	toString(size_t nbr)
{
	std::ostringstream	number;

	number << nbr;
	return number.str();
}

std::string	PhoneBook::createContactTable(void)
{
	std::string	table;

	formatter.appendField("Index");
	formatter.appendField("First Name");
	formatter.appendField("Last Name");
	formatter.appendField("Nickname");
	table = formatter.createTableHeader();

	for (size_t idx = 0; idx < numContacts; idx++) {
		formatter.appendField(toString(idx));
		formatter.appendField(contacts[idx].getFirstName());
		formatter.appendField(contacts[idx].getLastName());
		formatter.appendField(contacts[idx].getNickname());
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

	return name;
}

std::string	PhoneBook::getNumber(const std::string &prompt)
{
	bool		valid;
	std::string	number;

	do {
		number = ui.getUserInput(prompt);
		valid = validateNumber(number);
	} while (!valid);

	return number;
}

bool	PhoneBook::validateName(const std::string &name)
{
	if (!isAlphabetic(name)) {
		ui.showError("Only letters are expected.");
		return false;
	}
	return true;
}

bool	PhoneBook::isAlphabetic(const std::string &str)
{
	size_t	length = str.length();

	for (size_t i = 0; i < length; i++) {
		if (!std::isalpha(str[i]))
			return false;
	}
	return true;
}

bool	PhoneBook::validateNumber(const std::string &str)
{
	if (!isNumeric(str)) {
		ui.showError("Only positive numbers are expected.");
		return false;
	}
	if (str.length() > 14) {
		ui.showError("Input is too long. Please provide a shorter number.");
		return false;
	}
	return true;
}

bool	PhoneBook::isNumeric(const std::string &str)
{
	size_t	length = str.length();

	for (size_t i = 0; i < length; i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}
