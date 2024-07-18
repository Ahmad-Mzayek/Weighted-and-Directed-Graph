GraphWD is a C++ library that defines a class for representing weighted and directed graphs.
This implementation ensures that the graph contains neither negative weights nor self-loops nor duplicate edges.

Features:
- Adjacency List Representation: Efficient storage of graph data.
- Graph Properties: Retrieve graph order (number of vertices) and size (number of edges).
- Degree Calculation: Compute in-degree and out-degree for any vertex.
- Vertex Operations: Insert and remove vertices with validation.
- Edge Operations: Insert and remove edges with validation to prevent negative weights, self-loops, and duplicate edges.
- Graph Traversals: Perform depth-first search (DFS) and breadth-first search (BFS).
- Shortest Paths: Calculate shortest paths using Dijkstra's algorithm.
- Connectivity: Check if the graph is connected from a given starting vertex.
- Tree Check: Verify if the graph is a tree.
- Topological Sort: Obtain a topological sort using Kahn's algorithm.
- Future versions will include more algorithms.

License:
This project is licensed under the MIT License - see the LICENSE file for details.
