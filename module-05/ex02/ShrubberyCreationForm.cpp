/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:23:59 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/31 16:08:48 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>

#include "ShrubberyCreationForm.hpp"

const int SIGN = 145;
const int EXEC = 137;

static std::string generateTree(int height);

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", SIGN, EXEC)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", SIGN, EXEC)
{
    m_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeFormAction() const
{
    std::string target(m_target + "_shrubbery");
    std::ofstream file(target.c_str());

    file << generateTree(10);

    file.close();
}

static std::string generateTree(int height)
{
    if (height <= 0)
    {
        return "";
    }

    std::stringstream treeStream;

    for (int i = 1; i <= height; ++i)
    {
        for (int j = 0; j < height - i; ++j)
        {
            treeStream << " ";
        }

        for (int j = 0; j < 2 * i - 1; ++j)
        {
            treeStream << "*";
        }

        treeStream << "\n";
    }

    for (int i = 0; i < height - 2; ++i)
    {
        treeStream << " ";
    }
    treeStream << "|||\n";

    return treeStream.str();
}
