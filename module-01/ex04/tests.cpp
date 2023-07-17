/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:02:20 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/17 10:05:55 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cassert>

#include "replace.hpp"

void testStrReplace(void);

int main(void)
{
    testStrReplace();
}

void testStrReplace(void)
{
    std::string input = "Hello, world!";
    std::string search = "world";
    std::string replace = "everyone";
    std::string expectedOutput = "Hello, everyone!";

    strReplace(input, search, replace);

    assert(input == expectedOutput);

    std::cout << "Test passed: strReplace" << std::endl;
}
