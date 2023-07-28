/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:40:29 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 12:20:00 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
    : m_type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string& type)
    : m_type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;

    *this = src;
}

Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal assignment operator called" << std::endl;

    if (&rhs != this)
    {
        m_type = rhs.m_type;
    }

    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes some strange sound!" << std::endl;
}

std::string Animal::getType() const
{
    return m_type;
}
