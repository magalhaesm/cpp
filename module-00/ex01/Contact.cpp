/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:12:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/30 13:30:31 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string&	Contact::getFirstName(void)
{
	return (firstName);
}

const std::string&	Contact::getLastName(void)
{
	return (lastName);
}

const std::string&	Contact::getNickName(void)
{
	return (nickName);
}

const std::string&	Contact::getPhoneNumber(void)
{
	return (phoneNumber);
}

const std::string&	Contact::getDarkestSecret(void)
{
	return (darkestSecret);
}

void	Contact::setFirstName(const std::string& name)
{
	firstName = name;
}

void	Contact::setLastName(const std::string& name)
{
	lastName = name;
}

void	Contact::setNickName(const std::string& name)
{
	nickName = name;
}

void	Contact::setPhoneNumber(const std::string& number)
{
	phoneNumber = number;
}

void	Contact::setDarkestSecret(const std::string& secret)
{
	darkestSecret = secret;
}
