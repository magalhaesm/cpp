/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:58:20 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/17 10:01:31 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

void performStringReplacement(
    std::ifstream& inFile,
    std::ofstream& outFile,
    const std::string& search,
    const std::string& replace);
void strReplace(std::string& text, const std::string& search, const std::string& replace);
void handleError(const std::string& errorMessage);

#endif // !REPLACE_HPP
