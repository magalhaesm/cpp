/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:58:23 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/18 22:48:55 by mdias-ma         ###   ########.fr       */
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
    Fixed& operator=(const Fixed& rhs);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(const int raw);

    int toInt(void) const;
    float toFloat(void) const;

private:
    int m_rawBits;
    static const int FRACTIONAL_BITS;
};

std::ostream& operator<<(std::ostream& o, const Fixed& i);

#endif // !FIXED_HPP
