#include <iomanip>
#include <exception>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <list>
#include <ctime>

#include "PmergeMe.hpp"

template <typename Iterator>
void print(const std::string& lable, Iterator begin, Iterator end);

int strToInt(const std::string& str);
void testMergeInsertionSort(const std::vector<int>& input);
void parseArguments(const std::vector<std::string>& args, std::vector<int>& input);

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " {1..10}" << std::endl;
        return EXIT_FAILURE;
    }

    const std::vector<std::string> args(argv + 1, argv + argc);
    std::vector<int> input;

    try
    {
        parseArguments(args, input);
        testMergeInsertionSort(input);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

double get_msec(clock_t& start, clock_t& end)
{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

void testMergeInsertionSort(const std::vector<int>& input)
{
    print("Before: ", input.begin(), input.end());

    clock_t start, end;
    double vector_time, list_time;

    {
        start = clock();

        std::vector<int> xs(input.begin(), input.end());
        PmergeMe::sort(xs.begin(), xs.end());

        end = clock();

        if (!utils::is_sorted(xs.begin(), xs.end()))
        {
            throw std::runtime_error("failed to sort");
        }

        vector_time = get_msec(start, end);
        print("After:  ", xs.begin(), xs.end());
    }

    {
        start = clock();

        std::list<int> xs(input.begin(), input.end());
        PmergeMe::sort(xs.begin(), xs.end());

        end = clock();

        if (!utils::is_sorted(xs.begin(), xs.end()))
        {
            throw std::runtime_error("failed to sort");
        }

        list_time = get_msec(start, end);
    }

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector : " << vector_time << " ms\n";
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::list : " << list_time << " ms\n";
}

void parseArguments(const std::vector<std::string>& args, std::vector<int>& input)
{
    std::transform(args.begin(), args.end(), std::back_inserter(input), strToInt);
}

int strToInt(const std::string& str)
{
    std::stringstream ss(str);
    int val;
    if (!(ss >> val))
    {
        throw std::invalid_argument("conversion failed");
    }
    return val;
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
