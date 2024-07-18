/*
    @headerfile     GraphWD.hpp
    @version        1.0
    @author         Ahmad Mzayek
    @date           Thursday, July 18th, 2024
    @brief          Defines a class for `Weighted and Directed Graphs`.
    @note           The graph contains neither negative weights nor self-loops nor duplicate edges.
*/

#ifndef __GRAPH_WD_HPP_
#define __GRAPH_WD_HPP_

#include <map>
#include <string>
#include <vector>
#include <unordered_set>

// @typedef Vertex_t
typedef std::string Vertex_t;

/*
    @class      GraphWD
    @brief      Defines a weighted and directed graph data structure containing neither negative weights nor self-loops nor duplicate edges.
*/
class GraphWD final
{
private:
    std::map<Vertex_t, std::map<Vertex_t, size_t>> adjacencyList;

public:
    //  @brief      Prints the adjacency list of the graph to the standard output.
    void printAdjacencyList(void) const noexcept;

    /*
        @brief      Gets the order (number of vertices) of the graph.
        @returns    `size_t` The order of the graph.
    */
    size_t getOrder(void) const noexcept;

    /*
        @brief      Gets the size (number of edges) of the graph.
        @returns    `size_t` The size of the graph.
    */
    size_t getSize(void) const noexcept;

    /*
        @brief      Gets the in-degree (number of incoming edges) of a given vertex.
        @param      vertex The vertex of which the in-degree is to be computed.
        @returns    `size_t` The in-degree of the given vertex.
        @throws     `std::runtime_error` If the given vertex does not exist in the graph.
    */
    size_t getInDegree(const Vertex_t& vertex) const;

    /*
        @brief      Gets the out-degree (number of outgoing edges) of a given vertex.
        @param      vertex The vertex of which the out-degree is to be computed.
        @returns    `size_t` The out-degree of the given vertex.
        @throws     `std::runtime_error` If the given vertex does not exist in the graph.
    */
    size_t getOutDegree(const Vertex_t& vertex) const;

    /*
        @brief      Inserts a given vertex into the graph.
        @param      vertex The vertex to be inserted.
        @throws     `std::runtime_error` If the given vertex is invalid or if it already exists in the graph.
        @note       See also: `static bool GraphWD::isValidVertex(const Vertex_t& vertex) noexcept`.
    */
    void insertVertex(const Vertex_t& vertex);

    /*
        @brief      Removes a given vertex from the graph.
        @param      vertex The vertex to be removed.
        @throws     `std::runtime_error` If the given vertex does not exist in the graph.
    */
    void removeVertex(const Vertex_t& vertex);

    /*
        @brief      Inserts a given edge to the graph.
        @param      source The source vertex from which the edge will be inserted.
        @param      destination The destination vertex to which the edge will be inserted.
        @param      weight The non-negative weight of the edge to be inserted.
        @throws     `std::runtime_error` If either the given source vertex or the given destination vertex does not exist in the graph,
        @throws     or if an edge already exists between the given vertices, or if the given edge is a self-loop.
    */
    void insertEdge(const Vertex_t& source, const Vertex_t& destination, const size_t weight);

    /*
        @brief      Removes a given edge from the graph.
        @param      source The source vertex from which the edge will be removed.
        @param      destination The destination vertex to which the edge will be removed.
        @throws     `std::runtime_error` If either the given source vertex or the given destination vertex does not exist in the graph,
        @throws     or if no edge exists between the given vertices.
    */
    void removeEdge(const Vertex_t& source, const Vertex_t& destination);

    /*
        @brief      Checks whether a given vertex is valid.
        @param      vertex The vertex of which the validity is to be checked.
        @returns    `true` if the given vertex is valid, `false` otherwise.
        @note       A vertex is considered valid if and only if it is not empty, and all its characters are alphanumeric.
    */
    static bool isValidVertex(const Vertex_t& vertex) noexcept;

    /*
        @brief      Checks whether the graph is connected given a starting vertex.
        @param      startingVertex The vertex starting from which the graph is to be checked.
        @returns    `true` if the graph is connected, `false` otherwise.
        @throws     `std::runtime_error` If the given starting vertex does not exist in the graph.
        @note       The graph is connected if and only if all vertices are reachable from the given starting vertex.
    */
    bool isConnected(const Vertex_t& startingVertex) const;

    /*
        @brief      Checks whether the graph is a tree.
        @returns    `std::pair<bool, Vertex_t>` `{true, root}` if the graph is a tree, `{false, ""}` otherwise.
        @note       The graph is a tree if and only if it is connected and the in-degree of every vertex is 1, except for one (inDegree(root) == 0).
    */
    std::pair<bool, Vertex_t> isTree(void) const noexcept;

    /*
        @brief      Gets the depth-first search traversal of the graph given a starting vertex.
        @param      startingVertex The vertex starting from which the depth-first search will begin.
        @returns    `std::vector<Vertex_t>` The depth-first search traversal of the graph.
        @throws     `std::runtime_error` If the given starting vertex does not exist in the graph.
    */
    std::vector<Vertex_t> getDFS(const Vertex_t& startingVertex) const;

    /*
        @brief      Gets the breadth-first search traversal of the graph given a starting vertex.
        @param      startingVertex The vertex starting from which the breadth-first search will begin.
        @returns    `std::vector<Vertex_t>` The breadth-first search traversal of the graph.
        @throws     `std::runtime_error` If the given starting vertex does not exist in the graph.
    */
    std::vector<Vertex_t> getBFS(const Vertex_t& startingVertex) const;

    /*
        @brief      Gets the shortest path from a given source vertex to each of the other reachable vertices, using Dijkstra's shortest paths algorithm.
        @param      source The source vertex from which the shortest distances to each of the other reachable vertices is computed.
        @returns    `std::map<Vertex_t, size_t>` The reachable vertices and their respective shortest distance from the source vertex.
        @throws     `std::runtime_error` If the given source vertex does not exist in the graph.
    */
    std::map<Vertex_t, size_t> getDijkstraShortestPaths(const Vertex_t& source) const;

    /*
        @brief      Gets the topological sort of the graph, using Kahn's topological sorting algorithm.
        @returns    `std::pair<bool, std::vector<Vertex_t>>` `{true, sortedVertices}` if a topological sort exists, `{false, {}}` otherwise.
        @note       A topological sort of the graph exists if and only if the graph is acyclic.
    */
    std::pair<bool, std::vector<Vertex_t>> getKahnTopologicalSort(void) const noexcept;
};

#endif // __GRAPH_WD_HPP_