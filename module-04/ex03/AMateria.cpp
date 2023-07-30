/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:23:06 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/29 14:19:44 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria& src)
{
    *this = src;
}

AMateria::AMateria(std::string const& type)
    : m_type(type)
{
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    if (&rhs != this)
    {
        m_type = rhs.m_type;
    }

    return *this;
}

std::string const& AMateria::getType() const
{
    return m_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Using " << m_type << " on " << target.getName() << std::endl;
}
