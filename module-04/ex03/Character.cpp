/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:05:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/29 22:00:43 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    clearInventory();
}

Character::Character(const std::string name)
    : m_name(name)
{
    clearInventory();
}

Character::Character(const Character& src)
{
    *this = src;
}

Character::~Character()
{
    for (int idx = 0; idx < SLOTS; ++idx)
    {
        delete m_inventory[idx];
    }
}

Character& Character::operator=(const Character& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    m_name = rhs.m_name;

    for (int idx = 0; idx < SLOTS; ++idx)
    {
        if (rhs.m_inventory[idx])
        {
            delete m_inventory[idx];
            m_inventory[idx] = rhs.m_inventory[idx]->clone();
        }
    }

    return *this;
}

std::string const& Character::getName() const
{
    return m_name;
}

void Character::equip(AMateria* m)
{
    for (int idx = 0; idx < SLOTS; ++idx)
    {
        if (!m_inventory[idx])
        {
            m_inventory[idx] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (!isValidSlot(idx))
    {
        return;
    }

    m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (!isValidSlot(idx))
    {
        return;
    }

    m_inventory[idx]->use(target);
}

void Character::clearInventory(void)
{
    for (int idx = 0; idx < SLOTS; ++idx)
    {
        m_inventory[idx] = NULL;
    }
}

bool Character::isValidSlot(int idx)
{
    if (idx >= 0 && idx < SLOTS && m_inventory[idx])
    {
        return true;
    }

    return false;
}
