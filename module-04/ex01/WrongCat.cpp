/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:43:12 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/26 23:54:48 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    std::cout << m_type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << m_type << " destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow..." << std::endl;
}
