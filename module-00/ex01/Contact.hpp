/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:09:16 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/28 15:18:41 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <stdexcept>

class Contact
{
public:
	void	setFirstName(const std::string& firstName);
	void	setLastName(const std::string& lastName);
	void	setNickName(const std::string& nickName);
	void	setPhoneNumber(const std::string& phoneNumber);
	void	setDarkestSecret(const std::string& darkestSecret);

	const std::string&	getFirstName();
	const std::string&	getLastName();
	const std::string&	getNickName();
	const std::string&	getPhoneNumber();
	const std::string&	getDarkestSecret();

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	bool	validateName(const std::string& name);
	bool	validateNumber(const std::string& number);
};

#endif // !CONTACT_HPP
