/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:09:16 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/30 13:31:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <stdexcept>

class Contact
{
public:
	void	setFirstName(const std::string &name);
	void	setLastName(const std::string &name);
	void	setNickName(const std::string &name);
	void	setPhoneNumber(const std::string &number);
	void	setDarkestSecret(const std::string &secret);

	const std::string	&getFirstName();
	const std::string	&getLastName();
	const std::string	&getNickName();
	const std::string	&getPhoneNumber();
	const std::string	&getDarkestSecret();

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
};

#endif // !CONTACT_HPP
