/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:43:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/26 18:46:10 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat")
{
    std::cout << m_type << " constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << m_type << " destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}
