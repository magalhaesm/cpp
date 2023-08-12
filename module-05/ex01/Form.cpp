/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:03:53 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 17:25:35 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

const int Form::highestGrade = 1;
const int Form::lowestGrade = 150;

Form::Form()
    : m_name("")
    , m_signed(false)
    , m_gradeToSign(lowestGrade)
    , m_gradeToExecute(lowestGrade)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : m_name(name)
    , m_signed(false)
    , m_gradeToSign(gradeToSign)
    , m_gradeToExecute(gradeToExecute)
{
    validateGrade(m_gradeToSign);
    validateGrade(m_gradeToExecute);
}

Form::Form(const Form& copy)
    : m_name(copy.m_name)
    , m_signed(copy.m_signed)
    , m_gradeToSign(copy.m_gradeToSign)
    , m_gradeToExecute(copy.m_gradeToExecute)
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form&)
{
    return *this;
}

const std::string& Form::getName() const
{
    return m_name;
}

bool Form::getSigned() const
{
    return m_signed;
}

int Form::getGradeToSign() const
{
    return m_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return m_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (m_gradeToSign < bureaucrat.getGrade())
    {
        throw GradeTooLowException();
    }

    m_signed = true;
}

void Form::validateGrade(int grade)
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

Form::GradeTooHighException::GradeTooHighException()
    : std::invalid_argument("Grade is too high")
{
}

Form::GradeTooLowException::GradeTooLowException()
    : std::invalid_argument("Grade is too low")
{
}

std::ostream& operator<<(std::ostream& out, const Form& rhs)
{
    out << "Form name: " << rhs.getName() << std::endl
        << "Signed: " << std::boolalpha << rhs.getSigned() << std::endl
        << "Grade to sign: " << rhs.getGradeToSign() << std::endl
        << "Grade to execute: " << rhs.getGradeToExecute();
    return out;
}
