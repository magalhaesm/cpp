/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:01:17 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/12 17:37:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat&);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat&);

    const std::string& getName() const;
    int getGrade() const;
    void setGrade(int grade);

    void incrementGrade();
    void decrementGrade();

    void signForm(Form& form);

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

    const std::string m_name;
    int m_grade;

    static const int highestGrade;
    static const int lowestGrade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif // !BUREAUCRAT_HPP
