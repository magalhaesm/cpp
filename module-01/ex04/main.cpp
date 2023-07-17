/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias-ma <mdias-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:11:30 by mdias-ma          #+#    #+#             */
/*   Updated: 2023/07/17 10:00:52 by mdias-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "replace.hpp"

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        handleError("Usage: ./replace [filename] [search] [replace]");
    }

    std::string filename = argv[1];
    std::ifstream inFile(filename.c_str());
    if (!inFile)
    {
        handleError("Error: Failed to open input file");
    }

    filename += ".replace";
    std::ofstream outFile(filename.c_str());
    if (!outFile)
    {
        handleError("Error: Failed to open output file");
    }

    performStringReplacement(inFile, outFile, argv[2], argv[3]);

    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}
