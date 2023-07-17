/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:28:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/17 13:29:56 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    logLevels[0] = "DEBUG";
    logLevels[1] = "INFO";
    logLevels[2] = "WARNING";
    logLevels[3] = "ERROR";

    logFuncions[0] = &Harl::debug;
    logFuncions[1] = &Harl::info;
    logFuncions[2] = &Harl::warning;
    logFuncions[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
    int index = findLogLevelIndex(level);

    switch (index)
    {
    case 0:
        (this->*logFuncions[index++])();
        // fall through
    case 1:
        (this->*logFuncions[index++])();
        // fall through
    case 2:
        (this->*logFuncions[index++])();
        // fall through
    case 3:
        (this->*logFuncions[index++])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

int Harl::findLogLevelIndex(const std::string& level) const
{
    for (int index = 0; index < levels; index++)
    {
        if (level == logLevels[index])
        {
            return index;
        }
    }
    return -1;
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]\n"
                 "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup "
                 "burger.\n"
                 "I really do!"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]\n"
                 "I cannot believe adding extra bacon costs more money.\n"
                 "You didn't put enough bacon in my burger!\n"
                 "If you did, I wouldn't be asking for more! "
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]\n"
                 "I think I deserve to have some extra bacon for free.\n"
                 "I've been coming for years whereas you started working here since last month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]\n"
                 "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}
