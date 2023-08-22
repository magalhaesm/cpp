#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(4);

    std::sort(vec.begin(), vec.end());
    std::cout << std::distance(vec.begin(), vec.end()) << std::endl;
    std::vector<int>::iterator foundIter = easyfind(vec, 10);

    if (foundIter != vec.end())
    {
        std::cout << "Found: " << *foundIter << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
}
