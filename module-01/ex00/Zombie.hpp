/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:09:51 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/05 15:50:43 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie(std::string name);
    ~Zombie(void);

    void announce(void);

private:
    std::string zombieName;
};

#endif // !ZOMBIE_HPP
