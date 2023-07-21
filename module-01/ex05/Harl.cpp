/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:28:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/21 15:35:34 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    logLevels[0] = "DEBUG";
    logLevels[1] = "INFO";
    logLevels[2] = "WARNING";
    logLevels[3] = "ERROR";

    logFunctions[0] = &Harl::debug;
    logFunctions[1] = &Harl::info;
    logFunctions[2] = &Harl::warning;
    logFunctions[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
    logFunction log;

    for (size_t idx = 0; idx < levels; idx++)
    {
        if (level == logLevels[idx])
        {
            log = logFunctions[idx];
            (this->*log)();
            return;
        }
    }
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
