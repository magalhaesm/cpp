/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:58:20 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/19 00:40:02 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed(void)
    : m_rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
    : m_rawBits(value)
{
    std::cout << "Int constructor called" << std::endl;

    setRawBits(value << FRACTIONAL_BITS);
}

Fixed::Fixed(const float value)
    : m_rawBits(value)
{
    std::cout << "Float constructor called" << std::endl;

    setRawBits(roundf(value * (1 << FRACTIONAL_BITS)));
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;

    *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    setRawBits(rhs.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    return m_rawBits;
}

void Fixed::setRawBits(const int raw)
{
    m_rawBits = raw;
}

int Fixed::toInt(void) const
{
    return getRawBits() >> FRACTIONAL_BITS;
}

float Fixed::toFloat(void) const
{
    return getRawBits() / static_cast<float>(1 << FRACTIONAL_BITS);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fixed& in)
{
    out << in.toFloat();

    return out;
}
