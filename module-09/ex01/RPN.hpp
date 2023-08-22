/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:42:15 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/17 17:16:40 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>

enum TokenType
{
    NUMBER,
    OPERATOR,
};

class RPN
{
public:
    static int eval(const std::string& expression);

private:
    RPN();

    static TokenType lookup(char ch);
    static void processNumber(char ch);
    static void processOperator(char op);
    static void assign(int& term1, int& term2);

    static std::list<int> m_stack;
};

#endif // !RPN_HPP
