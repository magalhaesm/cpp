/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:19:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/24 16:56:55 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap bot1("Bot1");
    ClapTrap bot2("Bot2");

    std::cout << std::endl;
    bot2.attack("Bot1");
    bot1.takeDamage(10);

    std::cout << std::endl;
    bot1.beRepaired(10);

    std::cout << std::endl;
    bot2.attack("Bot1");
    bot1.takeDamage(10);

    std::cout << std::endl;
    bot2.attack("Bot1");
    bot2.attack("Bot1");
    bot2.attack("Bot1");
    bot2.attack("Bot1");
    bot2.attack("Bot1");
    bot2.attack("Bot1");
    bot2.attack("Bot1");
    bot2.attack("Bot1");
    bot2.attack("Bot1");
    bot2.attack("Bot1");

    bot2.beRepaired(20);

    std::cout << std::endl;
    return 0;
}
