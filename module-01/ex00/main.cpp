/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:10:18 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/05 14:33:46 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie murphy("Murphy");

    Zombie* teddy = new Zombie("Teddy");
    delete teddy;

    return 0;
}
