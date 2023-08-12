/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:11:44 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 18:22:32 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* Intern::createShrubberyCreationFrom(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

const Intern::FormCreatorEntry Intern::formCreators[knownForms] = {
    { "shrubbery creation", Intern::createShrubberyCreationFrom },
    { "robotomy request", Intern::createRobotomyRequestForm },
    { "presidential pardon", Intern::createPresidentialPardonForm },
};

Intern::Intern()
{
}

Intern::Intern(const Intern&)
{
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern&)
{
    return *this;
}

Intern::FormNotFound::FormNotFound()
    : std::invalid_argument("form not found")
{
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    AForm* instance = 0;

    for (int idx = 0; idx < knownForms; ++idx)
    {
        if (name == formCreators[idx].name)
        {
            instance = formCreators[idx].createForm(target);
            break;
        }
    }

    if (!instance)
    {
        throw FormNotFound();
    }

    std::cout << "Intern creates " << instance->getName() << std::endl;
    return instance;
}
