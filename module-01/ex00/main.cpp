/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:10:18 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 15:57:13 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main(void)
{
    Zombie murphy("Murphy");

    Zombie* teddy = newZombie("Teddy");

    randomChump("Foo");

    delete teddy;

    return 0;
}
