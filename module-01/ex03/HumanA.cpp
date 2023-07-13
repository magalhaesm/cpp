/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:25:45 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/13 13:58:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : m_name(name)
    , m_weapon(weapon)
{
}

void HumanA::attack(void)
{
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}
