/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:41:54 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 17:48:21 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
    : AAnimal("Dog")
{
    std::cout << m_type << " constructor called" << std::endl;

    m_brain = new Brain();
}

Dog::~Dog()
{
    delete m_brain;

    std::cout << m_type << " destructor called" << std::endl;
}

Dog::Dog(const Dog& src)
    : AAnimal(src)
{
    std::cout << m_type << " copy constructor called" << std::endl;

    *this = src;
}

Dog& Dog::operator=(const Dog& rhs)
{
    std::cout << m_type << " assignment operator called" << std::endl;

    if (&rhs != this)
    {
        m_brain = new Brain(*rhs.m_brain);
    }

    return *this;
}

bool Dog::areBrainsEqual(const Dog& rhs)
{
    return m_brain == rhs.m_brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof..." << std::endl;
}
