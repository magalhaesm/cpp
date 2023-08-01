/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:03:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/31 20:32:05 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
public:
    AForm(const std::string& name, int gradeToSign, int gradeToExecute = lowestGrade);
    AForm(const AForm&);
    virtual ~AForm();

    AForm& operator=(const AForm&);

    const std::string& getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(Bureaucrat const& executor) const;

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

    class FormNotAssignedException : public std::invalid_argument
    {
    public:
        FormNotAssignedException();
    };

protected:
    std::string m_target;

private:
    AForm();
    virtual void executeFormAction() const = 0;

    const std::string m_name;
    bool m_signed;
    const int m_gradeToSign;
    const int m_gradeToExecute;

    static const int highestGrade;
    static const int lowestGrade;

    void validateGrade(int grade);
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif // !FORM_HPP
