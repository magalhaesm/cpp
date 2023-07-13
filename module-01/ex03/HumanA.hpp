/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:25:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/13 14:00:39 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon& weapon);
    void attack(void);

private:
    std::string m_name;
    Weapon& m_weapon;
};

#endif // !HUMANA_HPP
