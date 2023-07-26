/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:41:54 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/26 18:54:15 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
    : Animal("Dog")
{
    std::cout << m_type << " constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << m_type << " destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof..." << std::endl;
}
