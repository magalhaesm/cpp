/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:41:42 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/30 18:45:52 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstddef>
#include <functional>
#include <ios>
#include <iostream> // std::cout
#include <iterator>
#include <utility>
#include <vector> // std::vector
#include <map>
#include <cmath>

#include "PmergeMe.hpp"
#include "utils.hpp"
#include "Slice.hpp"

template <typename T>
struct Inserter
{
    std::vector<T>& m_chain;

    Inserter(std::vector<T>& chain)
        : m_chain(chain)
    {
    }

    void operator()(const T& element, size_t max_insertion_idx)
    {
        typedef typename std::vector<T>::iterator Iterator;

        Iterator end = m_chain.begin() + max_insertion_idx;
        Iterator insertionPoint = std::upper_bound(m_chain.begin(), end, element);

        // std::cout << "Element: " << element << " insertion: " << *insertionPoint << '\n';
        m_chain.insert(insertionPoint, element);
    }
};

template <typename Container, typename Function>
void each_insertion_for(const Container& pend, Function inserter);

template <typename T>
struct Comparator
{
    size_t& count;

    Comparator(size_t& c)
        : count(c)
    {
        count = 0;
    }

    bool operator()(const T& a, const T& b)
    {
        count++;
        return std::less<T>()(a, b);
    }
};

template <typename Iterator>
void print(const std::string& lable, Iterator begin, Iterator end);
void print(const std::string& lable, const std::vector<int>& vec);

// TODO: entender as reais necessidades de uso desta classe
// iterar fatias da entrada
// [x] percorrer de 2 em 2, 4 em 4, etc.
// [x] comparar estas fatias (último elemento do grupo)
// [x] fazer swap
// [ ] criar lista de fatias para chain e pend
// [ ] [] deve retornar a base ou um iterador?
// [ ] < deve comparar o último
int main()
{
    std::vector<int> xs;

    // 8 7 100 27 46 11 53 2 13 0 15 5 17 18 14 28 20 19 21
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

    size_t total = 0;
    Comparator<size_t> comparer(total);

    print("==>", xs);

    size_t size = 1;
    Slice<std::vector<int>::iterator> slice(xs.begin(), size);

    size_t groups = size * 2;
    size_t length = xs.size() - (xs.size() % groups);

    for (size_t it = 0; it < length; it += groups, slice += 2)
    {
        if (slice[1] < slice[0])
        {
            iter_swap(slice, slice + 1);
        }
        std::cout << "slice: " << slice << " - slice + 1: " << slice + 1 << '\n';
    }

    std::vector<Slice<std::vector<int>::iterator> > chain;
    Inserter<Slice<std::vector<int>::iterator> > inserter(chain);
    std::vector<Slice<std::vector<int>::iterator> > pend;

    slice = Slice<std::vector<int>::iterator>(xs.begin(), size);
    for (size_t it = 0; it < length; it += groups, slice += 2)
    {
        pend.push_back(slice);
        chain.push_back(slice + 1);
    }

    std::cout << "CHAIN:\n";
    for (size_t idx = 0; idx < chain.size(); ++idx)
    {
        std::cout << chain[idx] << ' ';
    }
    std::cout << '\n';

    std::cout << "PEND:\n";
    for (size_t idx = 0; idx < pend.size(); ++idx)
    {
        std::cout << pend[idx] << ' ';
    }
    std::cout << '\n';

    each_insertion_for(pend, inserter);

    std::cout << "CHAIN:\n";
    for (size_t idx = 0; idx < chain.size(); ++idx)
    {
        std::cout << chain[idx] << ' ';
    }
    std::cout << '\n';

    // print("==>", xs);
    return 0;
}

template <typename Container, typename Function>
void each_insertion_for(const Container& pend, Function inserter)
{
    inserter(pend[0], 0);

    size_t groupIdx = 1;
    size_t prevGroupSize = 0;
    for (size_t power = 1; groupIdx < pend.size(); ++power)
    {
        size_t groupSize = (1 << power) - prevGroupSize;
        size_t groupLast = std::min(groupIdx + groupSize - 1, pend.size() - 1);
        size_t maxInsertionIdx = (1 << (power + 1)) - 1;

        for (size_t idx = groupLast; idx >= groupIdx; --idx)
        {
            inserter(pend[idx], maxInsertionIdx);
        }

        groupIdx += groupSize;
        prevGroupSize = groupSize;
    }
}

template <typename Iterator>
void print(const std::string& lable, Iterator begin, Iterator end)
{
    std::cout << lable << " [";

    std::cout << *begin++;
    while (begin != end)
    {
        std::cout << ", " << *begin;
        ++begin;
    }

    std::cout << "]\n";
}

void print(const std::string& lable, const std::vector<int>& vec)
{
    std::cout << lable << " [";

    std::ostream_iterator<int> output(std::cout, ", ");
    std::copy(vec.begin(), vec.end() - 1, output);
    std::cout << *(vec.end() - 1) << "]\n";

    std::cout << '\n';
}
