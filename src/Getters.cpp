/*
    @file           Getters.cpp
    @version        1.0
    @author         Ahmad Mzayek
    @date           Thursday, July 18th, 2024
    @brief          Implements graph characteristics getter methods defined in the class `GraphWD`.
*/

#include <stdexcept>
#include "GraphWD.hpp"
#include "TextColors.hpp"

size_t GraphWD::getOrder(void) const noexcept
{
    return this->adjacencyList.size();
}

size_t GraphWD::getSize(void) const noexcept
{
    size_t size = 0;
    for (const auto& [_, neighbors] : this->adjacencyList)
        size += neighbors.size();
    return size;
}

size_t GraphWD::getInDegree(const Vertex_t& vertex) const
{
    if (this->adjacencyList.find(vertex) == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Vertex `" + vertex + "` does not exist in the graph.\n" DEFAULT_COLOR);
    size_t inDegree = 0;
    for (const auto& [_, neighbors] : this->adjacencyList)
        if (neighbors.find(vertex) != neighbors.end())
            ++inDegree;
    return inDegree;
}

size_t GraphWD::getOutDegree(const Vertex_t& vertex) const
{
    const auto itVertex = this->adjacencyList.find(vertex);
    if (itVertex == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Vertex `" + vertex + "` does not exist in the graph.\n" DEFAULT_COLOR);
    return itVertex->second.size();
}