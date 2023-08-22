/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:25:19 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 00:28:46 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <exception>

#include "Span.hpp"

#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define FAIL "\033[1;7;31mFAIL\033[0m"

void print_title(const std::string& title);
void print_failure();

int gen(void);
void genRandomSeq(std::vector<int>& sequence, int size);

int main(void)
{
    {
        print_title("Test: Finding Shortest and Longest Spans");

        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }
    {
        print_title("Test: Throwing Exception for Insufficient Elements");

        Span sp = Span(5);

        sp.addNumber(42);
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            print_failure();
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        print_title("Test: Throwing Exception for Exceeding Span Size Limit");

        Span sp(10);

        std::vector<int> sequence;
        genRandomSeq(sequence, 10000);
        try
        {
            sp.addNumber(sequence.begin(), sequence.end());
            print_failure();
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        print_title("Test: Filling Span Using a Range of Iterators");

        Span sp(20000);

        std::vector<int> sequence;
        genRandomSeq(sequence, 15000);
        sp.addNumber(sequence.begin(), sequence.end());
        // sp.addNumber(0);
        // sp.addNumber(1);
        // sp.addNumber(1000000);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }

    return 0;
}

void genRandomSeq(std::vector<int>& sequence, int size)
{
    sequence.resize(size);
    srand(static_cast<unsigned int>(time(0)));
    std::generate(sequence.begin(), sequence.end(), gen);
}

int gen(void)
{
    return random() % 1000000;
}

void print_title(const std::string& title)
{
    std::cout << std::string(40, '-') << '\n';
    std::cout << GREEN << "\n" << title << "\n" << RESET << std::endl;
}

void print_failure()
{
    std::cout << FAIL << std::endl;
}
