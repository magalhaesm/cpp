/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:02:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 17:17:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

const int Bureaucrat::highestGrade = 1;
const int Bureaucrat::lowestGrade = 150;

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : m_name(name)
    , m_grade(lowestGrade)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
    : m_name(copy.m_name)
    , m_grade(copy.m_grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (&rhs != this)
    {
        m_grade = rhs.m_grade;
    }

    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return m_name;
}

int Bureaucrat::getGrade() const
{
    return m_grade;
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < highestGrade)
    {
        throw GradeTooHighException();
    }
    else if (grade > lowestGrade)
    {
        throw GradeTooLowException();
    }

    m_grade = grade;
}

void Bureaucrat::incrementGrade()
{
    setGrade(m_grade - 1);
}

void Bureaucrat::decrementGrade()
{
    setGrade(m_grade + 1);
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::invalid_argument("Grade is too high")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::invalid_argument("Grade is too low")
{
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return out;
}
