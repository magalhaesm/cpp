/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:27:26 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/16 12:18:39 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <stdexcept>

#include "BitcoinExchange.hpp"

BitcoinExchange::ExchangeRateDatabase BitcoinExchange::m_database;

static bool isValidDate(int year, int month, int day);

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange&)
{
    return *this;
}

Date BitcoinExchange::parseDate(const std::string& date)
{
    int year, month, day;

    if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    {
        throw std::runtime_error("invalid date format");
    }

    if (!isValidDate(year, month, day))
    {
        throw std::runtime_error("invalid date");
    }

    return date;
}

BTC BitcoinExchange::parseValue(const std::string& value)
{
    BTC amount;

    if (std::sscanf(value.c_str(), "%f", &amount) != 1)
    {
        throw std::runtime_error("invalid number");
    }

    if (amount < 0)
    {
        throw std::runtime_error("not a positive number");
    }

    if (amount > 1000)
    {
        throw std::runtime_error("too large a number");
    }

    return amount;
}

void BitcoinExchange::loadData(const std::string& database)
{
    std::string line;
    std::ifstream file(database.c_str());
    if (!file)
    {
        throw std::runtime_error("can't open database");
    }

    char* date = new char[11];
    float price;

    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::sscanf(line.c_str(), "%10s,%f", date, &price);
        m_database[Date(date)] = price;
    }

    delete[] date;
    file.close();
}

Price BitcoinExchange::findPrice(Date date)
{
    ExchangeRateDatabase::iterator it = m_database.lower_bound(date);

    if (it != m_database.begin())
    {
        --it;
    }

    return it->second;
}

static bool isValidDate(int year, int month, int day)
{
    bool isValidYear = (year >= 0) && (year <= 9999);
    bool isValidMonth = (month >= 1) && (month <= 12);
    bool isValidDay = (day >= 1) && (day <= 31);

    return isValidYear & isValidMonth & isValidDay;
}
