/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:34:31 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/29 22:24:29 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#define GREEN "\033[1;7;32m"
#define RESET "\033[0m"

void separator();
void print_title(const std::string title);

int main()
{
    print_title("Interface & recap");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    {
        print_title("Test Character Copy");

        IMateriaSource* src = new MateriaSource();

        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        Character* me = new Character("me");
        Character* bob = new Character("bob");

        bob->equip(src->createMateria("ice"));
        bob->equip(src->createMateria("cure"));

        *me = *bob; // Deep copy

        me->use(0, *me);
        me->use(1, *me);

        delete src;
        delete me;
        delete bob;
    }
    {
        print_title("Test Unequip");

        Ice* ice = new Ice();
        Character* bob = new Character("bob");

        bob->equip(ice);
        bob->unequip(0); // Do not delete

        std::cout << "there's nothing to use" << std::endl;
        bob->use(0, *bob);

        delete ice; // Delete here
        delete bob;
    }

    return 0;
}

void print_title(const std::string title)
{
    std::cout << std::string(40, '-') << std::endl;
    std::cout << GREEN << "\n" << title << "\n" << RESET << std::endl;
}
