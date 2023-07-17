/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:11:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/16 21:15:18 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

void performStringReplacement(
    std::ifstream& inFile,
    std::ofstream& outFile,
    const std::string& search,
    const std::string& replace);
void strReplace(std::string& text, const std::string& search, const std::string& replace);
void handleError(const std::string& errorMessage);

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        handleError("Error: Incorrect number of arguments");
    }

    std::ifstream inFile(argv[1]);
    if (!inFile)
    {
        handleError("Error: Failed to open input file");
    }

    std::string filename(argv[1]);
    filename += ".replace";
    std::ofstream outFile(filename.c_str());
    if (!outFile)
    {
        handleError("Error: Failed to open output file");
    }

    performStringReplacement(inFile, outFile, argv[2], argv[3]);

    return EXIT_SUCCESS;
}

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
