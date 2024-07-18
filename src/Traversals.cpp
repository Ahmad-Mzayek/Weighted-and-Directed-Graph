/*
    @file           Traversals.cpp
    @version        1.0
    @author         Ahmad Mzayek
    @date           Thursday, July 18th, 2024
    @brief          Implements depth-first search and breadth-first search traversal methods defined in the class `GraphWD`.
*/

#include <stack>
#include <queue>
#include <stdexcept>
#include "GraphWD.hpp"
#include "TextColors.hpp"

std::vector<Vertex_t> GraphWD::getDFS(const Vertex_t& startingVertex) const
{
    if (this->adjacencyList.find(startingVertex) == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Starting vertex `" + startingVertex + "` does not exist in the graph.\n" DEFAULT_COLOR);
    std::vector<Vertex_t> traversal;
    std::unordered_set<Vertex_t> visited;
    visited.insert(startingVertex);
    std::stack<Vertex_t> stack;
    stack.push(startingVertex);
    while (!stack.empty())
    {
        const Vertex_t& vertex = stack.top();
        stack.pop();
        traversal.push_back(vertex);
        const auto& neighbors = this->adjacencyList.at(vertex);
        for (const auto& [neighbor, _] : neighbors)
        {
            if (visited.find(neighbor) != visited.end())
                continue;
            visited.insert(neighbor);
            stack.push(neighbor);
        }
    }
    return traversal;
}

std::vector<Vertex_t> GraphWD::getBFS(const Vertex_t& startingVertex) const
{
    if (this->adjacencyList.find(startingVertex) == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Starting vertex `" + startingVertex + "` does not exist in the graph.\n" DEFAULT_COLOR);
    std::vector<Vertex_t> traversal;
    std::unordered_set<Vertex_t> visited;
    visited.insert(startingVertex);
    std::queue<Vertex_t> queue;
    queue.push(startingVertex);
    while (!queue.empty())
    {
        const Vertex_t& vertex = queue.front();
        queue.pop();
        traversal.push_back(vertex);
        const auto& neighbors = this->adjacencyList.at(vertex);
        for (const auto& [neighbor, _] : neighbors)
        {
            if (visited.find(neighbor) != visited.end())
                continue;
            visited.insert(neighbor);
            queue.push(neighbor);
        }
    }
    return traversal;
}