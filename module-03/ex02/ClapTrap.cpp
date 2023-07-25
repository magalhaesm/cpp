/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:18:33 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/25 16:28:49 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : m_name(name)
    , m_hitPoints(10)
    , m_energyPoints(10)
    , m_attackDamage(0)
{
    std::cout << "[ ClapTrap ] : " << m_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    *this = src;

    std::cout << "[ ClapTrap ] : Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    m_name = rhs.m_name;
    m_hitPoints = rhs.m_hitPoints;
    m_energyPoints = rhs.m_energyPoints;
    m_attackDamage = rhs.m_attackDamage;

    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (m_energyPoints <= 0)
    {
        std::cout << "[ ClapTrap ] : " << m_name << " can't attack, no energy left." << std::endl;
        return;
    }

    m_energyPoints--;

    std::cout << "[ ClapTrap ] : " << m_name << " attacks " << target << " causing "
              << m_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (m_hitPoints <= 0)
    {
        std::cout << "[ ClapTrap ] : " << m_name << " has no hit points to lose." << std::endl;
        return;
    }

    m_hitPoints -= amount;

    std::cout << "[ ClapTrap ] : " << m_name << " takes damage, losing " << amount << " hit points!"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_energyPoints <= 0)
    {
        std::cout << "[ ClapTrap ] : " << m_name << " can't repair, no energy left." << std::endl;
        return;
    }

    if (m_hitPoints <= 0)
    {
        std::cout << "[ ClapTrap ] : " << m_name << " can't repair, no hit points left."
                  << std::endl;
        return;
    }

    m_energyPoints--;
    m_hitPoints += amount;

    std::cout << "[ ClapTrap ] : " << m_name << " recovers " << amount << " hit points."
              << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ ClapTrap ] : " << m_name << " has been destroyed!" << std::endl;
}
