/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:44:10 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/29 21:50:43 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
    : m_nextSlot(0)
{
    clearInventory();
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    *this = src;
}

MateriaSource::~MateriaSource()
{
    for (int idx = 0; idx < SLOTS; ++idx)
    {
        delete m_inventory[idx];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

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

void MateriaSource::learnMateria(AMateria* materia)
{
    if (m_nextSlot < SLOTS)
    {
        m_inventory[m_nextSlot++] = materia;
        return;
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int idx = 0; idx < SLOTS; ++idx)
    {
        if (type == m_inventory[idx]->getType())
        {
            return m_inventory[idx]->clone();
        }
    }

    return 0;
}

void MateriaSource::clearInventory(void)
{
    for (int idx = 0; idx < SLOTS; ++idx)
    {
        m_inventory[idx] = NULL;
    }
}
