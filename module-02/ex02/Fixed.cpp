/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:58:20 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/20 11:46:22 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed(void)
    : m_rawBits(0)
{
}

Fixed::Fixed(const int value)
    : m_rawBits(value)
{
    setRawBits(value << FRACTIONAL_BITS);
}

Fixed::Fixed(const float value)
    : m_rawBits(value)
{
    setRawBits(roundf(value * (1 << FRACTIONAL_BITS)));
}

Fixed::Fixed(const Fixed& src)
{
    *this = src;
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    setRawBits(rhs.getRawBits());
    return *this;
}

bool Fixed::operator>(const Fixed& rhs) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++(void)
{
    this->m_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);

    this->m_rawBits++;
    return tmp;
}

Fixed& Fixed::operator--(void)
{
    this->m_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    this->m_rawBits--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
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

std::ostream& operator<<(std::ostream& out, const Fixed& in)
{
    out << in.toFloat();

    return out;
}
