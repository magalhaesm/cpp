/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:16:37 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/29 14:04:32 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif // !CURE_HPP
