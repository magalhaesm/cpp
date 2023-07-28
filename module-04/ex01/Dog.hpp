/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:41:10 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 17:28:57 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    ~Dog();

    Dog(const Dog& src);
    Dog& operator=(const Dog& rhs);

    bool areBrainsEqual(const Dog& rhs);
    void makeSound() const;

private:
    Brain* m_brain;
};

#endif // !DOG_HPP
