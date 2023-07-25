/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:19:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/25 16:27:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap bot1("Bot1");
    FragTrap bot2("Bot2");

    std::cout << std::endl;
    bot1.attack("Bot2");
    bot2.takeDamage(20);

    std::cout << std::endl;
    bot2.beRepaired(10);

    bot1.highFivesGuys();

    std::cout << std::endl;
    return 0;
}
