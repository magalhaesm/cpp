/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:16:48 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 18:09:08 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"

const int SIGN = 25;
const int EXEC = 5;

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", SIGN, EXEC)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", SIGN, EXEC)
{
    m_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::executeFormAction() const
{
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
