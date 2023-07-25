/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:19:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/25 17:52:16 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap bot1("Bot1");
    DiamondTrap bot2(bot1);
    DiamondTrap bot3("Bot2");
    bot2 = bot3;
    std::cout << std::endl;

    bot1.attack(bot2.getName());
    bot2.takeDamage(20);
    bot2.beRepaired(20);
    bot1.guardGate();
    bot1.highFivesGuys();

    std::cout << std::endl;
    bot1.whoAmI();
    std::cout << std::endl;

    return 0;
}
