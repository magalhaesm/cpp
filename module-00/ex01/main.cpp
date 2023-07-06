/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:31:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/05 14:42:42 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "userInterface.hpp"

int main(void)
{
    std::string cmd;
    PhoneBook phonebook;

    ui::displayInfo("Welcome to the phonebook!\n");
    ui::display("Available commands:");
    ui::display(" 1. ADD - Add a new contact");
    ui::display(" 2. SEARCH - Search for a contact");
    ui::display(" 0. EXIT - Exit the program");

    while (true)
    {
        cmd = ui::getUserInput("\nEnter a number (1: ADD, 2: SEARCH, 0: EXIT): ");
        if (cmd == "1")
            phonebook.addContact();
        else if (cmd == "2")
            phonebook.searchContact();
        else if (cmd == "0")
        {
            ui::displayWarning("Exiting the program...");
            break;
        }
        else
            ui::displayError("Invalid command! Please try again.");
    }
    return (EXIT_SUCCESS);
}
