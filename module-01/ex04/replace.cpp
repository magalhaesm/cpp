/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:59:59 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/17 10:00:37 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void performStringReplacement(
    std::ifstream& inFile,
    std::ofstream& outFile,
    const std::string& search,
    const std::string& replace)
{
    std::string line;

    while (getline(inFile, line))
    {
        strReplace(line, search, replace);
        outFile << line << std::endl;
    }
}

void handleError(const std::string& errorMessage)
{
    std::cout << errorMessage << std::endl;
    exit(EXIT_FAILURE);
}

void strReplace(std::string& text, const std::string& search, const std::string& replace)
{
    size_t position = 0;
    const size_t searchLength = search.length();
    const size_t replaceLength = replace.length();

    position = text.find(search, position);
    while (position != std::string::npos)
    {
        text.erase(position, searchLength);
        text.insert(position, replace);
        position += replaceLength;
        position = text.find(search, position);
    }
}
