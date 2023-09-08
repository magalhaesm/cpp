/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:54:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/09/08 20:46:12 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

#include "MutantStack.hpp"

void subjectTest();
template <typename T>
void print(T value);
template <typename T>
void testIterators(const T data[], int size);

int main()
{
    {
        int data[] = { 0, 1, 2, 3, 4, 5, 4, 7, 8, 9 };
        testIterators(data, sizeof(data) / sizeof(data[0]));
    }
    {
        std::string data[] = { "first", "second", "third", "fourth", "fifth" };
        testIterators(data, sizeof(data) / sizeof(data[0]));
    }

    subjectTest();
}

template <typename T>
void testIterators(const T data[], int size)
{
    MutantStack<T> mstack;
    for (int idx = 0; idx < size; ++idx)
    {
        mstack.push(data[idx]);
    }
    std::cout << "MutantStack:\n";
    std::for_each(mstack.begin(), mstack.end(), print<T>);
    std::cout << std::endl;
    std::for_each(mstack.rbegin(), mstack.rend(), print<T>);
    std::cout << std::endl;

    std::list<T> test;
    for (int idx = 0; idx < size; ++idx)
    {
        test.push_back(data[idx]);
    }
    std::cout << "List:\n";
    std::for_each(test.begin(), test.end(), print<T>);
    std::cout << std::endl;
    std::for_each(test.rbegin(), test.rend(), print<T>);
    std::cout << std::endl;
}

template <typename T>
void print(T value)
{
    std::cout << value << ' ';
}

void subjectTest()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // -------------------------------------------------------------------------
    std::cout << "test: lists\n";

    std::list<int> test;

    test.push_back(5);
    test.push_back(17);

    std::cout << test.back() << std::endl;

    test.pop_back();

    std::cout << test.size() << std::endl;

    test.push_back(3);
    test.push_back(5);
    test.push_back(737);
    // //[...]
    test.push_back(0);

    std::list<int>::iterator test_it = test.begin();
    std::list<int>::iterator test_ite = test.end();

    ++test_it;
    --test_it;
    while (test_it != test_ite)
    {
        std::cout << *test_it << std::endl;
        ++test_it;
    }
    std::list<int> l(test);
}
