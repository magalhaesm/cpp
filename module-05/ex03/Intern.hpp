/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:11:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/31 20:52:51 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <stdexcept>
#include <string>

#include "AForm.hpp"

class Intern
{
public:
    Intern(void);
    Intern(const Intern&);
    ~Intern(void);

    Intern& operator=(const Intern&);

    AForm* makeForm(const std::string& form, const std::string& target) const;

    class FormNotFound : public std::invalid_argument
    {
    public:
        FormNotFound();
    };

private:
    struct FormCreatorEntry
    {
        std::string name;
        AForm* (*createForm)(const std::string&);
    };

    static const int knownForms = 3;
    static const FormCreatorEntry formCreators[knownForms];

    static AForm* createShrubberyCreationFrom(const std::string&);
    static AForm* createRobotomyRequestForm(const std::string&);
    static AForm* createPresidentialPardonForm(const std::string&);
};

#endif // !INTERN_HPP
