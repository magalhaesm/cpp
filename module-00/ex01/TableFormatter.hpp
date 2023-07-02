/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TableFormatter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:27:07 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/02 12:57:46 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_FORMATTER_HPP
# define TABLE_FORMATTER_HPP

# include <sstream>
# include <iomanip>

class TableFormatter {

public:
	TableFormatter();
	std::string	createTableHeader(void);
	std::string	createTableRow(void);
	void		appendField(const std::string &str);

private:
	size_t		fieldWidth;
	size_t		tableColumns;
	std::string	buffer;

	std::string	formatField(const std::string &str);
	std::string	generateSeparatorRow(void);
	void		resetTable(void);
};

#endif // !TABLE_FORMATTER_HPP
