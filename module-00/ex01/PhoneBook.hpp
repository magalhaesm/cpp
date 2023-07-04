/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:24:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/04 13:09:17 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>

# include "Contact.hpp"
# include "TableFormatter.hpp"
# include "userInterface.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	void	addContact();
	void	searchContact();

private:
	static const int	CAPACITY = 8;

	size_t			numContacts;
	Contact			contacts[CAPACITY];
	TableFormatter	formatter;

	std::string		getText(const std::string &prompt);
	std::string		getNumber(const std::string &prompt);
	std::string		createContactTable(void);
	std::string		getContactInfo(const Contact &contact);

	void	addToContacts(const Contact &contact);
	bool	validateName(const std::string &name);
	bool	validateNumber(const std::string &str);
	bool	isAlphabetic(const std::string &str);
	bool	isNumeric(const std::string &str);
};

#endif // !PHONEBOOK_HPP
