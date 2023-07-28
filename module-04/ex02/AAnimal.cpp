/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:40:29 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 18:41:14 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
    : m_type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type)
    : m_type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;

    *this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
    std::cout << "Animal assignment operator called" << std::endl;

    if (&rhs != this)
    {
        m_type = rhs.m_type;
    }

    return *this;
}

void AAnimal::makeSound() const
{
    std::cout << "Animal makes some strange sound!" << std::endl;
}

std::string AAnimal::getType() const
{
    return m_type;
}
