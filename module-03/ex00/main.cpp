/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:19:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/23 17:15:16 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap bender("Bender");
    ClapTrap ershin("Ershin");

    std::cout << std::endl;
    ershin.attack("Bender");
    bender.takeDamage(10);

    std::cout << std::endl;
    bender.beRepaired(10);

    std::cout << std::endl;
    ershin.attack("Bender");
    bender.takeDamage(10);

    std::cout << std::endl;
    ershin.attack("Bender");
    ershin.attack("Bender");
    ershin.attack("Bender");
    ershin.attack("Bender");
    ershin.attack("Bender");
    ershin.attack("Bender");
    ershin.attack("Bender");
    ershin.attack("Bender");
    ershin.attack("Bender");
    ershin.attack("Bender");

    ershin.beRepaired(20);

    std::cout << std::endl;
    return 0;
}
