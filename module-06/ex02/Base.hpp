/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:29:40 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/03 22:22:33 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
    virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif // !BASE_HPP
