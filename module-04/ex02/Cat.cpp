/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:43:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 17:48:19 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
    : AAnimal("Cat")
{
    std::cout << m_type << " constructor called" << std::endl;

    m_brain = new Brain();
}

Cat::Cat(const Cat& src)
    : AAnimal(src)
{
    std::cout << m_type << " copy constructor called" << std::endl;

    *this = src;
}

Cat& Cat::operator=(const Cat& rhs)
{
    std::cout << m_type << " assignment operator called" << std::endl;

    if (&rhs != this)
    {
        m_brain = new Brain(*rhs.m_brain);
    }

    return *this;
}

bool Cat::areBrainsEqual(const Cat& rhs)
{
    return m_brain == rhs.m_brain;
}

Cat::~Cat()
{
    delete m_brain;

    std::cout << m_type << " destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}
