/*
    @file           Algorithms.cpp
    @version        1.0
    @author         Ahmad Mzayek
    @date           Thursday, July 18th, 2024
    @brief          Implements well-known algorithms methods defined in the class `GraphWD`.
*/

#include <queue>
#include <stdexcept>
#include <unordered_map>
#include "GraphWD.hpp"
#include "TextColors.hpp"

std::map<Vertex_t, size_t> GraphWD::getDijkstraShortestPaths(const Vertex_t& source) const
{
    if (this->adjacencyList.find(source) == this->adjacencyList.end())
        throw std::runtime_error(RED_BOLD "Starting vertex `" + source + "` does not exist in the graph.\n" DEFAULT_COLOR);
    auto compare = [](const std::pair<Vertex_t, size_t>& a, const std::pair<Vertex_t, size_t>& b) -> bool
        {
            return a.second > b.second;
        };
    std::priority_queue<
        std::pair<Vertex_t, size_t>,
        std::vector<std::pair<Vertex_t, size_t>>,
        decltype(compare)
    > minHeap(compare);
    std::map<Vertex_t, size_t> minDistances;
    for (const auto& vertex : this->adjacencyList)
        minDistances[vertex.first] = SIZE_MAX;
    minDistances[source] = 0;
    minHeap.push({ source, 0 });
    while (!minHeap.empty())
    {
        const auto [current, currentDistance] = minHeap.top();
        minHeap.pop();
        if (currentDistance > minDistances[current])
            continue;
        const auto& neighbors = this->adjacencyList.at(current);
        for (const auto& [neighbor, weight] : neighbors)
        {
            const size_t newDistance = currentDistance + weight;
            if (newDistance >= minDistances[neighbor])
                continue;
            minDistances[neighbor] = newDistance;
            minHeap.push({ neighbor, newDistance });
        }
    }
    for (auto itMap = minDistances.begin(); itMap != minDistances.end(); )
    {
        if (itMap->second == SIZE_MAX)
            itMap = minDistances.erase(itMap);
        else
            ++itMap;
    }
    return minDistances;
}

std::pair<bool, std::vector<Vertex_t>> GraphWD::getKahnTopologicalSort(void) const noexcept
{
    std::unordered_map<Vertex_t, size_t> inDegrees;
    for (const auto& [_, neighbors] : this->adjacencyList)
        for (const auto& [neighbor, _] : neighbors)
            ++inDegrees[neighbor];
    std::queue<Vertex_t> sources;
    for (const auto& [vertex, _] : this->adjacencyList)
        if (inDegrees[vertex] == 0)
            sources.push(vertex);
    std::vector<Vertex_t> sortedVertices;
    while (!sources.empty())
    {
        const Vertex_t source = sources.front();
        sources.pop();
        sortedVertices.push_back(source);
        const auto& neighbors = this->adjacencyList.at(source);
        for (const auto& [neighbor, _] : neighbors)
            if (--inDegrees[neighbor] == 0)
                sources.push(neighbor);
    }
    if (sortedVertices.size() != this->getOrder())
        return { false, {} };
    return { true, sortedVertices };
}