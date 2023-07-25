/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:34:53 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/24 16:25:53 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    m_hitPoints = 100;
    m_energyPoints = 50;
    m_attackDamage = 20;

    std::cout << "< ScavTrap > : " << m_name << " has been created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "< ScavTrap > : " << m_name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (m_energyPoints <= 0)
    {
        std::cout << "< ScavTrap > : " << m_name << " can't attack, no energy left." << std::endl;
        return;
    }

    m_energyPoints--;

    std::cout << "< ScavTrap > : " << m_name << " attacks " << target << " causing "
              << m_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "< ScavTrap > : " << m_name << " is now in Gate keeper mode!" << std::endl;
}
