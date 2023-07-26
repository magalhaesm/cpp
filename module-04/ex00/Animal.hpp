/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:40:02 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/26 18:58:39 by mdias-ma         ###   ########.fr       */
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
    Animal(const Animal& src);
    Animal& operator=(const Animal& rhs);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string m_type;
};

#endif // !ANIMAL_HPP
