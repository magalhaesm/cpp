#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <deque>
#include <vector>
#include <numeric>

#include "PmergeMe.hpp"

TEST_CASE("isSorted function tests")
{
    SUBCASE("with sorted containers")
    {
        std::vector<int> vec(10);
        std::iota(vec.begin(), vec.end(), 0);
        CHECK(PmergeMe::isSorted(vec.begin(), vec.end()));

        std::deque<int> lst(10);
        std::iota(lst.begin(), lst.end(), 0);
        CHECK(PmergeMe::isSorted(lst.begin(), lst.end()));
    }

    SUBCASE("with unsorted containers")
    {
        std::vector<int> vec(10);
        std::iota(vec.begin(), vec.end(), 0);
        vec[5] = 100;
        CHECK_FALSE(PmergeMe::isSorted(vec.begin(), vec.end()));

        std::deque<int> lst(10);
        std::iota(lst.begin(), lst.end(), 0);
        lst[5] = 100;
        CHECK_FALSE(PmergeMe::isSorted(lst.begin(), lst.end()));
    }
}
