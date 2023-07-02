/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInterface.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:49:27 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/02 12:57:31 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINTERFACE_HPP
# define USERINTERFACE_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class UserInterface {

public:
	std::string	getUserInput(const std::string& prompt);

	void	showMessage(const std::string& message);
	void	showError(const std::string& message);
};

#endif // !USERINTERFACE_HPP
