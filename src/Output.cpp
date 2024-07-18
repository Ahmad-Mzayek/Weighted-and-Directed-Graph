/*
    @file           Output.cpp
    @version        1.0
    @author         Ahmad Mzayek
    @date           Thursday, July 18th, 2024
    @brief          Implements output-related methods defined in the class `GraphWD`.
*/

#include <iostream>
#include "GraphWD.hpp"
#include "TextColors.hpp"

void GraphWD::printAdjacencyList(void) const noexcept
{
    for (const auto& [vertex, neighbors] : this->adjacencyList)
    {
        std::cout << YELLOW << '[' << BLUE_BOLD << vertex << YELLOW << ']' << MAGENTA_BOLD << "\t-->\t" << DEFAULT_COLOR;
        for (const auto& [neighbor, weight] : neighbors)
            std::cout << YELLOW << '(' << CYAN_BOLD << neighbor << YELLOW << ", " << MAGENTA_BOLD << weight << YELLOW << "), " << DEFAULT_COLOR;
        std::cout << YELLOW << "\b\b." DEFAULT_COLOR << std::endl;
    }
}