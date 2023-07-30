/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:02:35 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/30 17:54:28 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : m_grade(grade)
    , m_name(name)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : m_name(src.m_name)
{
    *this = src;
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
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
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
    : std::invalid_argument("Grade is too high.")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::invalid_argument("Grade is too low.")
{
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& in)
{
    out << in.getName() << ", bureaucrat grade " << in.getGrade() << ".";
    return out;
}
