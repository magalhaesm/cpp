/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:57:45 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/29 11:50:59 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"

class AMateria
{
public:
    AMateria();
    AMateria(const AMateria& src);
    AMateria(std::string const& type);
    virtual ~AMateria();

    AMateria& operator=(const AMateria& rhs);
    std::string const& getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

protected:
    std::string m_type;
};

#endif // !AMATERIA_HPP
