/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:23:59 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 18:12:50 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "RobotomyRequestForm.hpp"

const int SIGN = 72;
const int EXEC = 45;

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", SIGN, EXEC)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", SIGN, EXEC)
{
    m_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeFormAction() const
{
    srand(time(NULL));
    const bool success = (rand() % 2 == 0);

    if (success)
    {
        std::cout << "Robotomy on " << m_target << " has been successful!"
                  << std::endl;
    }
    else
    {
        std::cout << "Robotomy on " << m_target << " has failed." << std::endl;
    }
}
