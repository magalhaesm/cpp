/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:01:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/05 14:41:36 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

std::string uppercase(std::string);

int main(int argc, const char** argv)
{
    std::string str;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (EXIT_SUCCESS);
    }
    for (int i = 1; i < argc; i++)
    {
        str = argv[i];
        std::cout << uppercase(str);
    }
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}

std::string uppercase(std::string str)
{
    size_t length = str.length();

    for (size_t j = 0; j < length; j++)
        str[j] = std::toupper(str[j]);

    return (str);
}
