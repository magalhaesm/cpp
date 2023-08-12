/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:03:53 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 17:56:53 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const int AForm::highestGrade = 1;
const int AForm::lowestGrade = 150;

AForm::AForm()
    : m_name("")
    , m_signed(false)
    , m_gradeToSign(lowestGrade)
    , m_gradeToExecute(lowestGrade)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : m_name(name)
    , m_signed(false)
    , m_gradeToSign(gradeToSign)
    , m_gradeToExecute(gradeToExecute)
{
    validateGrade(m_gradeToSign);
    validateGrade(m_gradeToExecute);
}

AForm::AForm(const AForm& copy)
    : m_target(copy.m_target)
    , m_name(copy.m_name)
    , m_signed(copy.m_signed)
    , m_gradeToSign(copy.m_gradeToSign)
    , m_gradeToExecute(copy.m_gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm& rhs)
{
    if (&rhs != this)
    {
        m_target = rhs.m_target;
    }

    return *this;
}

const std::string& AForm::getName() const
{
    return m_name;
}

bool AForm::getSigned() const
{
    return m_signed;
}

int AForm::getGradeToSign() const
{
    return m_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return m_gradeToExecute;
}

const std::string& AForm::getTarget() const
{
    return m_target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (m_gradeToSign < bureaucrat.getGrade())
    {
        throw GradeTooLowException();
    }

    m_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!getSigned())
    {
        throw FormNotAssignedException();
    }

    if (m_gradeToExecute < executor.getGrade())
    {
        throw GradeTooLowException();
    }

    executeFormAction();
}

void AForm::validateGrade(int grade)
{
    if (grade < highestGrade)
    {
        throw GradeTooHighException();
    }
    else if (grade > lowestGrade)
    {
        throw GradeTooLowException();
    }
}

AForm::GradeTooHighException::GradeTooHighException()
    : std::invalid_argument("grade is too high")
{
}

AForm::GradeTooLowException::GradeTooLowException()
    : std::invalid_argument("grade is too low")
{
}

AForm::FormNotAssignedException::FormNotAssignedException()
    : std::invalid_argument("form not assigned")
{
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form name: " << form.getName() << '\n'
        << "Signed: " << std::boolalpha << form.getSigned() << '\n'
        << "Grade to sign: " << form.getGradeToSign() << '\n'
        << "Grade to execute: " << form.getGradeToExecute();
    return out;
}
