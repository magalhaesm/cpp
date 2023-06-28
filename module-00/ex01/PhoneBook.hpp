/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:24:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/28 14:53:54 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CAPACITY 8

# include "Contact.hpp"
# include "UserInterface.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void	addContact();
	void	searchContact();
	void	exit();

private:
	size_t			contactIndex;
	Contact			contacts[CAPACITY];
	Contact			validationContact;
	UserInterface	ui;
};

#endif // !PHONEBOOK_HPP
