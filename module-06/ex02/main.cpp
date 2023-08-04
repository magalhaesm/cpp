/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:36:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/04 15:47:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    Base* basePtr = generate();
    Base& baseRef = *basePtr;

    identify(basePtr);
    identify(baseRef);

    delete basePtr;
}

Base* generate(void)
{
    std::srand(std::time(0));

    switch (std::rand() % 3)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "Object type: A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "Object type: B" << std::endl;
        return;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "Object type: C" << std::endl;
        return;
    }
}

void identify(Base& p)
{
    Base base;

    try
    {
        base = dynamic_cast<A&>(p);
        std::cout << "Object type: A" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        base = dynamic_cast<B&>(p);
        std::cout << "Object type: B" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        base = dynamic_cast<C&>(p);
        std::cout << "Object type: C" << std::endl;
        return;
    }
    catch (...)
    {
    }
}
