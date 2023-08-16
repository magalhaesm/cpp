/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:23:09 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/16 20:17:02 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdlib>
#include <iostream>

#include "Array.hpp"

#define RESET "\033[0m"
#define GREEN "\033[1;32m"

void print_title(const std::string& title);
template <typename T>
void testArray(const T data[], const int MAX_SIZE);

int main()
{
    {
        print_title("Integer Array Test");
        int data[] = { 0, 1, 2, 3, 4, 5, 4, 7, 8, 9 };
        testArray(data, sizeof(data) / sizeof(data[0]));
        std::cout << std::endl;
    }
    {
        print_title("String Array Test");
        std::string data[] = { "first", "second", "third", "fourth", "fifth" };
        testArray(data, sizeof(data) / sizeof(data[0]));
    }
}

template <typename T>
void testArray(const T data[], const int MAX_SIZE)
{
    Array<T> numbers(MAX_SIZE);
    for (int idx = 0; idx < MAX_SIZE; idx++)
    {
        numbers[idx] = data[idx];
        std::cout << numbers[idx] << ' ';
    }
    std::cout << std::endl;

    try
    {
        numbers[-2] = data[0];
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        numbers[MAX_SIZE] = data[0];
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void print_title(const std::string& title)
{
    std::cout << std::string(40, '-') << '\n';
    std::cout << GREEN << "\n" << title << "\n" << RESET << std::endl;
}
