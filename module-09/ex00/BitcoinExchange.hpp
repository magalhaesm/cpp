/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:26:28 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/16 12:04:31 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

typedef float BTC;
typedef float Price;
typedef std::string Date;

class BitcoinExchange
{
public:
    static Date parseDate(const std::string& date);
    static BTC parseValue(const std::string& value);
    static void loadData(const std::string& database);
    static Price findPrice(Date date);

private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange&);
    ~BitcoinExchange();
    BitcoinExchange operator=(const BitcoinExchange&);

    typedef std::map<Date, Price> ExchangeRateDatabase;
    static ExchangeRateDatabase m_database;
};

#endif // !BITCOINEXCHANGE_HPP
