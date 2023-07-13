/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:17:52 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/13 18:09:50 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    setType(type);
}

void Weapon::setType(std::string type)
{
    m_type = type;
}

std::string const& Weapon::getType(void) const

{
    return m_type;
}
