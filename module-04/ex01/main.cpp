/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:48:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 17:37:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define GREEN "\033[1;7;32m"
#define RESET "\033[0m"

void separator();
void print_title(const std::string title);
void test_deep_copy();

int main()
{
    const Animal* j = new Dog();
    separator();
    const Animal* i = new Cat();
    separator();

    delete j; // should not create a leak
    separator();
    delete i;

    print_title("ANIMALS ARRAY");
    const Animal* animals[4] = { new Cat(), new Cat(), new Dog(), new Dog() };
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "\nAnimal: " << i + 1 << std::endl;
        delete animals[i];
    }

    test_deep_copy();

    return 0;
}

void test_deep_copy()
{
    print_title("TEST COPIES");

    Cat a;
    separator();
    Cat b(a);
    separator();

    if (a.areBrainsEqual(b))
        std::cout << "\nThat's a shallow copy! Weird!\n" << std::endl;
    else
        std::cout << "Deep copy! The objects have their own set of ideas." << std::endl;
    separator();
}

void print_title(const std::string title)
{
    std::cout << GREEN << "\n" << title << "\n" << RESET << std::endl;
}

void separator()
{
    std::cout << "\n";
}
