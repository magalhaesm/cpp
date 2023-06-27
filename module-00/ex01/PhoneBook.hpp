/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:24:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/27 10:52:23 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define CAPACITY 8

# include "Contact.hpp"

class PhoneBook
{
public:

private:
	Contact	contacts[CAPACITY];
};

#endif // !PHONEBOOK_HPP
