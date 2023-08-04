/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:37:24 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/08/03 21:03:44 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

#include "Serializer.hpp"

int main()
{
    Data* dataPtr = new Data;
    dataPtr->value = 42;

    std::cout << "Data value before conversion: " << dataPtr->value << std::endl;

    uintptr_t serializedPtr = Serializer::serialize(dataPtr);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    std::string status = (deserializedPtr == dataPtr) ? "successful" : "failed";
    std::cout << "Serialization and deserialization " << status << "!" << std::endl;

    std::cout << "Data value after conversion: " << deserializedPtr->value << std::endl;
    delete dataPtr;

    return 0;
}
