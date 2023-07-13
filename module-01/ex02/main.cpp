/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:17:18 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/13 12:53:08 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string separator(30, '*');

    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << separator << std::endl;
    std::cout << "Memory addresses:" << std::endl;
    std::cout << "string: " << &str << std::endl;
    std::cout << "stringPTR: " << &stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl;

    std::cout << separator << std::endl;
    std::cout << "Values:" << std::endl;
    std::cout << "string: " << str << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
}
