/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:40:02 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 12:19:48 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const std::string& type);
    virtual ~Animal();

    Animal(const Animal& src);
    Animal& operator=(const Animal& rhs);

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string m_type;
};

#endif // !ANIMAL_HPP
