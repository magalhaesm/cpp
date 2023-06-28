/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:12:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/28 15:19:02 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string&	Contact::getFirstName(void)
{
	return firstName;
}

const std::string&	Contact::getLastName(void)
{
	return lastName;
}

const std::string&	Contact::getNickName(void)
{
	return nickName;
}

const std::string&	Contact::getPhoneNumber(void)
{
	return phoneNumber;
}

const std::string&	Contact::getDarkestSecret(void)
{
	return darkestSecret;
}

void	Contact::setFirstName(const std::string& firstName)
{
	if (!validateName(firstName))
		throw std::runtime_error("Invalid first name.");
	this->firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	if (!validateName(lastName))
		throw std::runtime_error("Invalid last name.");
	this->lastName = lastName;
}

void	Contact::setNickName(const std::string& nickName)
{
	if (!validateName(nickName))
		throw std::runtime_error("Invalid nick name.");
	this->nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	if (!validateNumber(phoneNumber))
		throw std::runtime_error("Invalid phone number.");
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

bool	Contact::validateName(const std::string& name)
{
	size_t	length = name.length();

	for (size_t i = 0; i < length; i++) {
		if (!std::isalpha(name[i]))
			return (false);
	}
	return (true);
}

bool	Contact::validateNumber(const std::string& number)
{
	size_t	length = number.length();

	for (size_t i = 0; i < length; i++) {
		if (!std::isdigit(number[i]))
			return (false);
	}
	return (true);
}
