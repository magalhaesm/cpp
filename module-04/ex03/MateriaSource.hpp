/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:44:05 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/29 19:09:50 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& rhs);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const& type);

private:
    const static int SLOTS = 4;

    int m_nextSlot;
    AMateria* m_inventory[SLOTS];

    void clearInventory(void);
};

#endif // !MATERIASOURCE_HPP
