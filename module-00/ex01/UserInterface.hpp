/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:49:27 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/06/28 09:49:58 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACE_HPP
# define USERINTERFACE_HPP

#include <string>
#include <iostream>

class UserInterface
{
public:
	void		showMessage(const std::string& message);
	std::string	getUserInput(const std::string& prompt);
};

#endif // !USERINTERFACE_HPP
