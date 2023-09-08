/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:53:24 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 14:57:28 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type Sequence;
    typedef typename Sequence::iterator iterator;
    typedef typename Sequence::const_iterator const_iterator;
    typedef typename Sequence::reverse_iterator reverse_iterator;
    typedef typename Sequence::const_reverse_iterator const_reverse_iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    const_iterator begin() const
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

    const_iterator end() const
    {
        return this->c.end();
    }

    reverse_iterator rbegin()
    {
        return this->c.rbegin();
    }

    const_reverse_iterator rbegin() const
    {
        return this->c.rbegin();
    }

    reverse_iterator rend()
    {
        return this->c.rend();
    }

    const_reverse_iterator rend() const
    {
        return this->c.rend();
    }
};

#endif // !MUTANTSTACK_HPP
