/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TableFormatter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:27:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/05 14:42:16 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLEFORMATTER_HPP
#define TABLEFORMATTER_HPP

#include <sstream>
#include <iomanip>

class TableFormatter
{
public:
    TableFormatter(void);
    std::string createTableHeader(void);
    std::string createTableRow(void);
    void appendField(const std::string& str);

private:
    size_t fieldWidth;
    size_t tableColumns;
    std::string buffer;

    std::string formatField(const std::string& str);
    std::string truncate(const std::string& str, size_t width);
    std::string generateSeparatorRow(void);
    void resetTable(void);
};

#endif // !TABLEFORMATTER_HPP
