/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:31:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/02 12:41:17 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "UserInterface.hpp"

int	main(void)
{
	UserInterface	ui;
	PhoneBook		phonebook(ui);
	std::string		cmd;

	ui.showMessage("Welcome to the phonebook program!\n");
	ui.showMessage("Available commands:");
	ui.showMessage("1. ADD - Add a new contact");
	ui.showMessage("2. SEARCH - Search for a contact");
	ui.showMessage("0. EXIT - Exit the program");

	while (true) {
		cmd = ui.getUserInput("\nEnter a command (1: ADD, 2: SEARCH, 0: EXIT): ");
		if (cmd == "1")
			phonebook.addContact();
		else if (cmd == "2")
			phonebook.searchContact();
		else if (cmd == "0") {
			ui.showMessage("Exiting the program...");
			break;
		}
		else
			ui.showError("Invalid command! Please try again.");
	}
	return (EXIT_SUCCESS);
}
