/*
    @file           Booleans.cpp
    @version        1.0
    @author         Ahmad Mzayek
    @date           Thursday, July 18th, 2024
    @brief          Implements all methods of return type `bool` defined in the class `GraphWD`.
*/

#include <queue>
#include <stdexcept>
#include <unordered_map>
#include "GraphWD.hpp"
#include "TextColors.hpp"

bool GraphWD::isValidVertex(const Vertex_t& vertex) noexcept
{
    if (vertex.empty())
        return false;
    for (const char character : vertex)
        if (!isalnum(character))
            return false;
    return true;
}

bool GraphWD::isConnected(const Vertex_t& startingVertex) const
{
    return this->getDFS(startingVertex).size() == this->getOrder();
}

std::pair<bool, Vertex_t> GraphWD::isTree(void) const noexcept
{
    std::unordered_map<Vertex_t, size_t> inDegrees;
    for (const auto& [_, neighbors] : this->adjacencyList)
        for (const auto& [neighbor, _] : neighbors)
            if (++inDegrees[neighbor] == 2)
                return { false, "" };
    if (inDegrees.size() != this->getOrder() - 1)
        return { false, "" };
    for (const auto& [vertex, _] : this->adjacencyList)
        if (inDegrees.find(vertex) == inDegrees.end())
        {
            if (this->isConnected(vertex))
                return { true, vertex };
            break;
        }
    return { false, "" };
}