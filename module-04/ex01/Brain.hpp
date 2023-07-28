/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:55:14 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 12:32:20 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
public:
    Brain();
    ~Brain();

    Brain(const Brain& src);
    Brain& operator=(const Brain& rhs);

private:
    std::string ideas[100];
};

#endif // !BRAIN_HPP
