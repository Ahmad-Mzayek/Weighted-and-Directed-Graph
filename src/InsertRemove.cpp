/*
    @file           InsertRemove.cpp
    @version        1.0
    @author         Ahmad Mzayek
    @date           Thursday, July 18th, 2024
    @brief          Implements methods related to insertion and deletion of vertices and edges into and from the graph, defined in the class `GraphWD`.
*/

#include <stdexcept>
#include "GraphWD.hpp"
#include "TextColors.hpp"

void GraphWD::insertVertex(const Vertex_t& vertex)
{
    if (!GraphWD::isValidVertex(vertex))
        throw std::runtime_error(RED_BOLD "Vertex `" + vertex + "` is not valid.\n" DEFAULT_COLOR);
    if (this->adjacencyList.find(vertex) != this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Vertex `" + vertex + "` already exists in the graph.\n" DEFAULT_COLOR);
    this->adjacencyList[vertex];
}

void GraphWD::removeVertex(const Vertex_t& vertex)
{
    const auto itVertex = this->adjacencyList.find(vertex);
    if (itVertex == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Vertex `" + vertex + "` does not exist in the graph.\n" DEFAULT_COLOR);
    this->adjacencyList.erase(itVertex);
    for (auto& [_, neighbors] : this->adjacencyList)
        neighbors.erase(vertex);
}

void GraphWD::insertEdge(const Vertex_t& source, const Vertex_t& destination, const size_t weight)
{
    auto itSource = this->adjacencyList.find(source);
    if (itSource == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Source vertex `" + source + "` does not exist in the graph.\n" DEFAULT_COLOR);
    if (this->adjacencyList.find(destination) == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Destination vertex `" + destination + "` does not exist in the graph.\n" DEFAULT_COLOR);
    auto& neighbors = itSource->second;
    if (neighbors.find(destination) != neighbors.end())
        throw std::runtime_error(RED_BOLD "An edge already exists from vertex `" + source + "` to vertex `" + destination + "`.\n" DEFAULT_COLOR);
    if (source == destination)
        throw std::runtime_error(RED_BOLD "Self loops are not allowed.\n" DEFAULT_COLOR);
    neighbors[destination] = weight;
}

void GraphWD::removeEdge(const Vertex_t& source, const Vertex_t& destination)
{
    auto itSource = this->adjacencyList.find(source);
    if (itSource == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Source vertex `" + source + "` does not exist in the graph.\n" DEFAULT_COLOR);
    if (this->adjacencyList.find(destination) == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Destination vertex `" + destination + "` does not exist in the graph.\n" DEFAULT_COLOR);
    auto& neighbors = itSource->second;
    auto itDestination = neighbors.find(destination);
    if (itDestination == neighbors.end())
        throw std::runtime_error(RED_BOLD "No edge exists from `" + source + "` to `" + destination + "`.\n" DEFAULT_COLOR);
    neighbors.erase(itDestination);
}