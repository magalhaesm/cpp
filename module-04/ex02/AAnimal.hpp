/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:40:02 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 18:40:14 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
public:
    AAnimal();
    AAnimal(const std::string& type);
    virtual ~AAnimal();

    AAnimal(const AAnimal& src);
    AAnimal& operator=(const AAnimal& rhs);

    virtual void makeSound() const = 0;
    std::string getType() const;

protected:
    std::string m_type;
};

#endif // !AANIMAL_HPP
