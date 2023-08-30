#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <list>
#include <vector>
#include <cmath>
#include <numeric>

#include "PmergeMe.hpp"
#include "Slice.hpp"
#include "utils.hpp"

TEST_CASE("isSorted function tests")
{
    SUBCASE("with sorted containers")
    {
        std::vector<int> vec(10);
        std::iota(vec.begin(), vec.end(), 0);
        CHECK(PmergeMe::isSorted(vec.begin(), vec.end()));

        std::list<int> lst(10);
        std::iota(lst.begin(), lst.end(), 0);
        CHECK(PmergeMe::isSorted(lst.begin(), lst.end()));
    }

    SUBCASE("with unsorted containers")
    {
        std::vector<int> vec(10);
        std::iota(vec.begin(), vec.end(), 0);
        vec[5] = 100;
        CHECK_FALSE(PmergeMe::isSorted(vec.begin(), vec.end()));

        std::list<int> lst(10);
        std::iota(lst.begin(), lst.end(), 0);
        lst.insert(lst.begin(), 100);
        CHECK_FALSE(PmergeMe::isSorted(lst.begin(), lst.end()));
    }
}

TEST_CASE("Slice tests")
{
    std::vector<int> xs = {

        8, 7, 100, 27, 46, 11, 53, 2, 13, 0, 15, 5, 17, 18, 14, 28, 20, 19, 21
    };

    SUBCASE("Iteration")
    {
        size_t iterations = std::log2(xs.size());

        size_t size = 1;
        while (iterations--)
        {
            Slice<std::vector<int>::iterator> slice(xs.begin(), size);

            size_t groups = size * 2;
            size_t length = xs.size() - (xs.size() % groups);

            for (size_t it = 0; it < length; it += groups, slice += 2)
            {
                CHECK(xs[it + size - 1] == slice[0]);
            }
            size *= 2;
        }
    }

    SUBCASE("Using + operator")
    {
        Slice<std::vector<int>::iterator> slice(xs.begin(), 1);

        for (size_t idx = 0; idx < xs.size(); ++idx)
        {
            CHECK(xs[idx] == *(slice + idx));
        }
    }
}
