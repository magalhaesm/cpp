/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:49:27 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/29 23:37:26 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACE_HPP
# define USERINTERFACE_HPP

#include <string>
#include <iostream>

class UserInterface
{
public:
	/* Display a message on the standard output. */
	void		showMessage(const std::string& message);
	std::string	getUserInput(const std::string& prompt);
	void		log(const std::string& message);
};

#endif // !USERINTERFACE_HPP
