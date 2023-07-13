/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:25:58 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/13 14:17:21 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : m_name(name)
    , m_weapon(NULL)
{
}

void HumanB::setWeapon(Weapon& weapon)
{
    m_weapon = &weapon;
}

void HumanB::attack(void) const
{
    if (!m_weapon)
    {
        std::cout << m_name << " doesn't have a weapon!" << std::endl;
        return;
    }

    std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}
