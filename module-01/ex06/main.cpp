/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:22:28 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/17 13:27:48 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Harl.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./harlFilter [LOG LEVEL]" << std::endl;
        return EXIT_FAILURE;
    }

    Harl harl;

    harl.complain(argv[1]);

    return EXIT_SUCCESS;
}
