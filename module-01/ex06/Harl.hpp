/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:30:52 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/17 13:30:14 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
public:
    Harl(void);
    void complain(std::string level);

private:
    typedef void (Harl::*logFunction)(void);

    static const int levels = 4;

    std::string logLevels[levels];
    logFunction logFuncions[levels];

    int findLogLevelIndex(const std::string& level) const;

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif // !HARL_HPP
