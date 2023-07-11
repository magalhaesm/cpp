/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:11:44 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/05 16:20:04 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int N = 5;
    Zombie* zombies = zombieHorde(N, "Awaaay");

    for (int i = 0; i < N; i++)
        zombies[i].announce();

    delete[] zombies;
}
