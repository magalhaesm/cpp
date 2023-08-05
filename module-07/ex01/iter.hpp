#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*function)(T&))
{
    if (!array)
    {
        return;
    }

    for (size_t idx = 0; idx < length; ++idx)
    {
        function(array[idx]);
    }
}

template <typename T>
void printElement(T element)
{
    std::cout << element << ' ';
}

template <typename T>
void doubleElement(T element)
{
    std::cout << element + element << ' ';
}

#endif // !ITER_HPP
