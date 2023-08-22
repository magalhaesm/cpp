/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:25:19 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/16 11:55:18 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "BitcoinExchange.hpp"

const char DELIMITER[] = " | ";
const char CSV_FILE[] = "data.csv";

void processLine(const std::string& line, size_t pos);
void printError(const std::string& errorMsg);
bool openInputFile(const char* filename, std::ifstream& file);

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream file;
    if (!openInputFile(argv[1], file))
    {
        return EXIT_FAILURE;
    }

    try
    {
        BitcoinExchange::loadData(CSV_FILE);
    }
    catch (const std::exception& e)
    {
        printError(e.what());
        return EXIT_FAILURE;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pos = line.find(DELIMITER);
        if (pos != std::string::npos)
        {
            processLine(line, pos);
        }
        else
        {
            printError("bad input => " + line);
        }
    }
    file.close();
    return EXIT_SUCCESS;
}

void processLine(const std::string& line, size_t pos)
{
    std::string input;
    try
    {
        input = line.substr(0, pos);
        Date date = BitcoinExchange::parseDate(input);

        input = line.substr(pos + 3);
        BTC amount = BitcoinExchange::parseValue(input);

        Price price = BitcoinExchange::findPrice(date);

        std::cout << date << " => " << amount << " = " << price * amount << '\n';
    }
    catch (const std::exception& e)
    {
        printError(std::string(e.what()) + " => " + input);
    }
}

void printError(const std::string& errorMsg)
{
    std::cout << "Error: " << errorMsg << std::endl;
}

bool openInputFile(const char* filename, std::ifstream& file)
{
    file.open(filename);
    if (!file)
    {
        printError("could not open file '" + std::string(filename) + "'.");
        return false;
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        printError("file '" + std::string(filename) + "' is empty.");
        return false;
    }

    return true;
}
