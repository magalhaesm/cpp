#include <algorithm>
#include <iostream>
#include <iterator>

#include <vector>
#include <list>

#include "Slice.hpp"
#include "PmergeMe.hpp"

template <typename Iterator>
void print(const std::string& lable, Iterator begin, Iterator end);

template <typename T>
void print(const std::string& lable, const std::vector<T>& vec);

template <typename Container, typename Function>
void each_insertion_for(const Container& pend, Function inserter);

int main()
{
    std::vector<int> xs;

    xs.push_back(8);
    xs.push_back(7);
    xs.push_back(100);
    xs.push_back(27);
    xs.push_back(46);
    xs.push_back(11);
    xs.push_back(53);
    xs.push_back(2);
    xs.push_back(13);
    xs.push_back(0);
    xs.push_back(15);
    xs.push_back(5);
    xs.push_back(17);
    xs.push_back(18);
    xs.push_back(14);
    xs.push_back(28);
    xs.push_back(20);
    xs.push_back(19);
    xs.push_back(21);

    // xs.push_back(21);

    // xs.push_back(3);
    // xs.push_back(26);
    // xs.push_back(10);
    // xs.push_back(36);
    // xs.push_back(6);
    // xs.push_back(56);
    // xs.push_back(37);
    // xs.push_back(31);
    // xs.push_back(30);
    // xs.push_back(23);
    // xs.push_back(43);
    // xs.push_back(42);
    // xs.push_back(68);
    // xs.push_back(73);

    print("==>", xs);
    PmergeMe::sort(xs.begin(), xs.end());
    print("==>", xs);
}

#include <iostream>
#include <vector>

template <typename T>
void print(const std::string& lable, const std::vector<T>& vec)
{
    std::cout << lable << " [";

    std::ostream_iterator<T> output(std::cout, ", ");
    std::copy(vec.begin(), vec.end() - 1, output);
    std::cout << *(vec.end() - 1) << "]\n";
}

template <typename Iterator>
void print(const std::string& lable, Iterator begin, Iterator end)
{
    std::cout << lable << " [";

    std::cout << *begin;
    ++begin;
    while (begin != end)
    {
        std::cout << ", " << *begin;
        ++begin;
    }

    std::cout << "]\n";
}
