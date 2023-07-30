/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:01:17 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/30 17:54:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& src);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& rhs);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::invalid_argument
    {
    public:
        GradeTooHighException();
    };

    class GradeTooLowException : public std::invalid_argument
    {
    public:
        GradeTooLowException();
    };

private:
    Bureaucrat();

    int m_grade;
    const std::string m_name;

    void setGrade(int grade);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& in);

#endif // !BUREAUCRAT_HPP
