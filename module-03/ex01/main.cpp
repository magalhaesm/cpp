/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:19:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/25 16:26:52 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap bot1("Bot1");
    ScavTrap bot2("Bot2");
    std::cout << std::endl;

    bot1.guardGate();

    std::cout << std::endl;
    bot1.attack("Bot2");
    bot2.takeDamage(20);

    std::cout << std::endl;
    bot2.beRepaired(10);

    std::cout << std::endl;
    return 0;
}
