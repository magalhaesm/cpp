#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main(void)
{
    {
        std::vector<int> xs;

        xs.push_back(1);
        xs.push_back(2);
        xs.push_back(5);
        xs.push_back(3);
        xs.push_back(4);

        std::vector<int>::iterator foundIter = easyfind(xs, 10);

        if (foundIter != xs.end())
        {
            std::cout << "Found: " << *foundIter << std::endl;
        }
        else
        {
            std::cout << "Not found" << std::endl;
        }
    }
    {
        std::list<int> xs;

        xs.push_back(1);
        xs.push_back(2);
        xs.push_back(5);
        xs.push_back(3);
        xs.push_back(4);

        std::list<int>::iterator foundIter = easyfind(xs, 10);

        if (foundIter != xs.end())
        {
            std::cout << "Found: " << *foundIter << std::endl;
        }
        else
        {
            std::cout << "Not found" << std::endl;
        }
    }
}
