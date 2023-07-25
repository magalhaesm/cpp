/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:43:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/25 13:59:51 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name)
    , FragTrap(name)
    , ScavTrap(name)
{
    m_name = name;
    ClapTrap::m_name = name + "_clap_name";

    m_hitPoints = FragTrap::m_hitPoints;
    m_energyPoints = ScavTrap::m_energyPoints;
    m_attackDamage = FragTrap::m_attackDamage;

    std::cout << "{ DiamondTrap } : " << m_name << " has been created!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << " - DiamondTrap name: " << m_name << std::endl;
    std::cout << " - ClapTrap name: " << ClapTrap::m_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "{ DiamondTrap } : " << m_name << " has been destroyed!" << std::endl;
}
