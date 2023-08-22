#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
    return std::find(container.begin(), container.end(), toFind);
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int toFind)
{
    return std::find(container.begin(), container.end(), toFind);
}

#endif // !EASYFIND_HPP
