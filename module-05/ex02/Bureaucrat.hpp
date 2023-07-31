/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:01:17 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/31 13:09:04 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat
{
public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat&);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat&);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm&);
    void executeForm(AForm const& form);

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

    static const int highestGrade;
    static const int lowestGrade;

    void setGrade(int grade);
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif // !BUREAUCRAT_HPP
