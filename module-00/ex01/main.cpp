/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:31:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/03 15:49:16 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "UserInterface.hpp"

int	main(void)
{
	UserInterface	ui;
	PhoneBook		phonebook(ui);
	std::string		cmd;

	ui.displayMessage("Welcome to the phonebook program!\n");
	ui.displayMessage("Available commands:");
	ui.displayMessage("1. ADD - Add a new contact");
	ui.displayMessage("2. SEARCH - Search for a contact");
	ui.displayMessage("0. EXIT - Exit the program");

	while (true) {
		cmd = ui.getUserInput("\nEnter a number (1: ADD, 2: SEARCH, 0: EXIT): ");
		if (cmd == "1")
			phonebook.addContact();
		else if (cmd == "2")
			phonebook.searchContact();
		else if (cmd == "0") {
			ui.displayMessage("Exiting the program...");
			break;
		}
		else
			ui.displayError("Invalid command! Please try again.");
	}
	return (EXIT_SUCCESS);
}
