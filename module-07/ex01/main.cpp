/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:19:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/16 20:16:54 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "iter.hpp"

int main(void)
{
    // Print
    {
        const int array[] = { 1, 2, 3, 4, 5 };
        iter(array, sizeof(array) / sizeof(int), printElement);
        std::cout << std::endl;
    }
    {
        const float array[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
        iter(array, sizeof(array) / sizeof(float), printElement);
        std::cout << std::endl;
    }
    {
        std::string array[] = { "first", "second", "third", "fourth", "fifth" };
        iter(array, sizeof(array) / sizeof(std::string), printElement);
        std::cout << std::endl;
    }
    // Double
    {
        const int array[] = { 1, 2, 3, 4, 5 };
        iter(array, sizeof(array) / sizeof(int), doubleElement);
        std::cout << std::endl;
    }
    {
        const float array[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
        iter(array, sizeof(array) / sizeof(float), doubleElement);
        std::cout << std::endl;
    }
    {
        std::string array[] = { "first", "second", "third", "fourth", "fifth" };
        iter(array, sizeof(array) / sizeof(std::string), doubleElement);
        std::cout << std::endl;
    }
}
