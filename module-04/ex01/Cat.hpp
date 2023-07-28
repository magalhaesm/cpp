/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:42:22 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/28 17:29:02 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat();
    ~Cat();

    Cat(const Cat& src);
    Cat& operator=(const Cat& rhs);

    bool areBrainsEqual(const Cat& rhs);
    void makeSound() const;

private:
    Brain* m_brain;
};

#endif // !CAT_HPP
