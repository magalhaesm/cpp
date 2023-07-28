/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:55:16 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 12:32:36 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain copy constructor called" << std::endl;

    *this = src;
}

Brain& Brain::operator=(const Brain& rhs)
{
    std::cout << "Brain assignment operator called" << std::endl;

    for (int idx = 0; idx < 100; ++idx)
    {
        ideas[idx] = rhs.ideas[idx];
    }

    return *this;
}
