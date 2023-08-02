/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionStrategy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:56:14 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/02 18:25:17 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONSTRATEGY_HPP
#define CONVERSIONSTRATEGY_HPP

#include "AConversionStrategy.hpp"

class CharConversionStrategy : public AConversionStrategy
{
public:
    void convert(const std::string& literal) const;
};

class IntConversionStrategy : public AConversionStrategy
{
public:
    void convert(const std::string& literal) const;
};

class FloatConversionStrategy : public AConversionStrategy
{
public:
    void convert(const std::string& literal) const;
};

class DoubleConversionStrategy : public AConversionStrategy
{
public:
    void convert(const std::string& literal) const;
};

class PseudoLiteralConversionStrategy : public AConversionStrategy
{
public:
    void convert(const std::string& literal) const;
};

class InvalidConversionStrategy : public AConversionStrategy
{
public:
    void convert(const std::string& literal) const;
};

#endif // !CONVERSIONSTRATEGY_HPP
