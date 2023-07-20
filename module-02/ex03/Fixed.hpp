/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:58:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/20 14:31:27 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& src);
    ~Fixed(void);

    Fixed& operator=(const Fixed& rhs);

    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    Fixed& operator+=(const Fixed& rhs);
    Fixed& operator++(void);
    Fixed operator++(int);
    Fixed& operator--(void);
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(const int raw);

    int toInt(void) const;
    float toFloat(void) const;

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int m_rawBits;
    static const int FRACTIONAL_BITS;
};

std::ostream& operator<<(std::ostream& o, const Fixed& i);

#endif // !FIXED_HPP
