/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:25:52 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/13 14:09:30 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(std::string name);

    void attack(void) const;
    void setWeapon(Weapon& weapon);

private:
    std::string m_name;
    Weapon* m_weapon;
};

#endif // !HUMANB_HPP
