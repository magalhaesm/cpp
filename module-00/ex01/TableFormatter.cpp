/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TableFormatter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:27:21 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/04 11:50:08 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TableFormatter.hpp"

static const char SEP = '|';
static const char LINE = '-';
static const char CORNER = '+';

TableFormatter::TableFormatter()
{
	fieldWidth = 10;
	tableColumns = 0;
}

std::string	TableFormatter::generateSeparatorRow(void)
{
	std::string line;
	std::string column;

	line += CORNER;
	column = std::string(fieldWidth, LINE);

	for (size_t i = 0; i < tableColumns; i++)
		line += column + CORNER;

	return line;
}

std::string	TableFormatter::createTableHeader(void)
{
	std::string header;
	std::string separator = generateSeparatorRow();

	header = separator + '\n';
	header += SEP + buffer + '\n';
	header += separator + '\n';
	resetTable();

	return header;
}

std::string	TableFormatter::createTableRow(void)
{
	std::string row;

	row += SEP + buffer + '\n';
	row += generateSeparatorRow() + '\n';
	resetTable();

	return row;
}

void	TableFormatter::appendField(const std::string &str)
{
	buffer.append(formatField(str) + SEP);
	tableColumns++;
}

void	TableFormatter::resetTable()
{
	buffer.erase();
	tableColumns = 0;
}

std::string	TableFormatter::formatField(const std::string &str)
{
	std::ostringstream row;

	row << std::right << std::setw(fieldWidth) << truncate(str, fieldWidth);
	return row.str();
}

std::string	TableFormatter::truncate(const std::string &str, size_t width)
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + '.');
	return str;
}
