/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:35:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/25 15:17:20 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    m_hitPoints = 100;
    m_energyPoints = 100;
    m_attackDamage = 30;

    std::cout << "( FragTrap ) : " << m_name << " has been created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "( FragTrap ) : " << m_name << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (m_energyPoints <= 0)
    {
        std::cout << "( FragTrap ) : " << m_name << " can't high five, no energy left."
                  << std::endl;
        return;
    }

    m_energyPoints--;

    std::cout << "( FragTrap ) : " << m_name << " says: Give me some high fives, guys!"
              << std::endl;
}
