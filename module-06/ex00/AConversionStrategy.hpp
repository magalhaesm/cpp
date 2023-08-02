/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AConversionStrategy.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:25:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 18:48:38 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACONVERSIONSTRATEGY_HPP
#define ACONVERSIONSTRATEGY_HPP

#include <string>

struct ConversionPack
{
    bool is_char_valid;
    bool is_int_valid;
    bool is_float_valid;
    bool is_double_valid;

    char char_value;
    int int_value;
    float float_value;
    double double_value;
};

class AConversionStrategy
{
public:
    AConversionStrategy();
    AConversionStrategy(const AConversionStrategy&);
    virtual ~AConversionStrategy();

    AConversionStrategy& operator=(const AConversionStrategy&);

    virtual void convert(const std::string& literal) const = 0;
};

std::ostream& operator<<(std::ostream&, const ConversionPack&);

#endif // !ACONVERSIONSTRATEGY_HPP
