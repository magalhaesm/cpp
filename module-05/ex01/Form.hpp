/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:03:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/31 09:37:09 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
public:
    Form(std::string name, int gradeToSign, int gradeToExecute = lowestGrade);
    Form(const Form&);
    ~Form();

    Form& operator=(const Form&);

    const std::string& getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);

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
    Form();

    const std::string m_name;
    bool m_signed;
    const int m_gradeToSign;
    const int m_gradeToExecute;

    static const int highestGrade;
    static const int lowestGrade;

    void validateGrade(int grade);
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif // !FORM_HPP
