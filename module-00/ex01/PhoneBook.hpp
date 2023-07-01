/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:24:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/01 11:44:14 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CAPACITY 8

# include "Contact.hpp"
# include "TableFormatter.hpp"
# include "UserInterface.hpp"

# include <iomanip>

class PhoneBook
{
public:
	PhoneBook();
	void	addContact();
	void	searchContact();

private:
	size_t			numContacts;
	Contact			contacts[CAPACITY];
	TableFormatter	formatter;
	UserInterface	ui;

	std::string	getText(const std::string &prompt);
	std::string	getNumber(const std::string &prompt);
	std::string	createContactTable(void);
	size_t		calculateStartIndex(void);
	void		addToContacts(const Contact &contact);

	bool	validateName(const std::string &name);
	bool	validateNumber(const std::string &str);
	bool	isAlphabetic(const std::string &str);
	bool	isNumeric(const std::string &str);
	size_t	next(void);
};

#endif // !PHONEBOOK_HPP
