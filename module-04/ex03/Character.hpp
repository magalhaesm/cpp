/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:04:42 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/29 20:59:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character(const std::string name);
    Character(const Character& src);
    ~Character();

    Character& operator=(const Character& rhs);

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

protected:
    const static int SLOTS = 4;

    std::string m_name;
    AMateria* m_inventory[SLOTS];

    void clearInventory(void);
    bool isValidSlot(int idx);

private:
    Character();
};

#endif // !CHARACTER_HPP
