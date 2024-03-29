/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:34:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/10 17:54:42 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string toString(size_t nbr);

PhoneBook::PhoneBook(void)
    : numContacts(0)
{
}

void PhoneBook::addContact()
{
    Contact newContact;

    ui::displayWarning("\n[+] Add new contact:");
    newContact.setFirstName(getText("First name: "));
    newContact.setLastName(getText("Last name: "));
    newContact.setNickname(getText("Nickname: "));
    newContact.setPhoneNumber(getNumber("Phone number: "));
    newContact.setDarkestSecret(ui::getUserInput("Darkest secret: "));

    addToContacts(newContact);
    ui::displayInfo("New contact has been added!");
}

void PhoneBook::addToContacts(const Contact& contact)
{
    static size_t index;

    contacts[index % CAPACITY] = contact;
    index++;
    numContacts = (index < CAPACITY) ? index : CAPACITY;
}

void PhoneBook::searchContact()
{
    std::string number;
    size_t index;

    if (!numContacts)
    {
        ui::displayError("\nThe phonebook is currently empty.");
        return;
    }

    ui::displayWarning("\n[+] Search for contact:");
    ui::display(createContactTable());
    do
    {
        number = getNumber("[+] Please choose an index to display: ");
        index = std::atoi(number.c_str());

        if (index >= numContacts)
            ui::displayError("Invalid index. Please choose one in the list.");
    } while (index >= numContacts);

    ui::display(getContactInfo(contacts[index]));
}

std::string PhoneBook::getContactInfo(const Contact& contact)
{
    std::string info;
    std::string separator(45, '*');

    info += "\n" + separator + "\n";
    info += "Contact Information:\n";
    info += "- First Name: " + contact.getFirstName() + '\n';
    info += "- Last Name: " + contact.getLastName() + '\n';
    info += "- Nickname: " + contact.getNickname() + '\n';
    info += "- Phone Number: " + contact.getPhoneNumber() + '\n';
    info += "- Darkest Secret: " + contact.getDarkestSecret() + '\n';
    info += separator;

    return info;
}

std::string PhoneBook::createContactTable(void)
{
    std::string table;

    formatter.appendField("Index");
    formatter.appendField("First Name");
    formatter.appendField("Last Name");
    formatter.appendField("Nickname");
    table = formatter.createTableHeader();

    for (size_t idx = 0; idx < numContacts; idx++)
    {
        formatter.appendField(toString(idx));
        formatter.appendField(contacts[idx].getFirstName());
        formatter.appendField(contacts[idx].getLastName());
        formatter.appendField(contacts[idx].getNickname());
        table += formatter.createTableRow();
    }

    return table;
}

std::string PhoneBook::getText(const std::string& prompt)
{
    bool valid;
    std::string name;

    do
    {
        name = ui::getUserInput(prompt);
        valid = validateName(name);
    } while (!valid);

    return name;
}

std::string PhoneBook::getNumber(const std::string& prompt)
{
    bool valid;
    std::string number;

    do
    {
        number = ui::getUserInput(prompt);
        valid = validateNumber(number);
    } while (!valid);

    return number;
}

bool PhoneBook::validateName(const std::string& name)
{
    if (!isAlphabetic(name))
    {
        ui::displayError("Only letters are expected.");
        return false;
    }
    return true;
}

bool PhoneBook::isAlphabetic(const std::string& str)
{
    size_t length = str.length();

    for (size_t i = 0; i < length; i++)
    {
        if (!std::isalpha(str[i]))
            return false;
    }
    return true;
}

bool PhoneBook::validateNumber(const std::string& str)
{
    if (!isNumeric(str))
    {
        ui::displayError("Only positive numbers are expected.");
        return false;
    }
    if (str.length() > 14)
    {
        ui::displayError("Input is too long. Please provide a shorter number.");
        return false;
    }
    return true;
}

bool PhoneBook::isNumeric(const std::string& str)
{
    size_t length = str.length();

    for (size_t i = 0; i < length; i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

static std::string toString(size_t nbr)
{
    std::ostringstream number;

    number << nbr;
    return number.str();
}
