/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:08:03 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/13 18:22:22 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
    Weapon(std::string type);

    std::string const& getType(void) const;
    void setType(std::string type);

private:
    std::string m_type;
};

#endif // !WEAPON_HPP
