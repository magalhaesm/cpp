/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:10:01 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/05 15:56:10 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
    : zombieName(name)
{
    announce();
}

void Zombie::announce(void)
{
    std::cout << zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << zombieName << ": No more... braiiinnz..." << std::endl;
}
