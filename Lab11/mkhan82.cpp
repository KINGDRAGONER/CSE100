#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// https://freecodecamp.org/news/prims-algorithm-explained-with-pseudocode/
// prim(graph):
//     # Initialize an empty set to hold the vertices in the minimum spanning tree
//     mst = empty set

//     # Select the first vertex to start the tree
//     startVertex = first vertex in graph
//     mst.add(startVertex)

//     # Initialize the set of edges to consider
//     edges = edges connected to startVertex

//     # Iterate until all vertices are in the minimum spanning tree
//     while mst has fewer vertices than graph:
//         # Find the minimum edge in the set of edges
//         minEdge, minWeight = findMinEdge(edges)

//         # Add the vertex to the minimum spanning tree
//         mst.add(minEdge)

//         # Add the edges connected to the vertex to the set of edges to consider
//         for edge in edges connected to minEdge:
//             if edge is not in mst:
//                 edges.add(edge)

//         # Remove the minimum edge from the set of edges to consider
//         edges.remove(minEdge)

//     # Return the minimum spanning tree as an array
//     return mst as an array
// The implimentation using Prim's algorithm

void primMST(vector<vector<int>> &MST_GRAPH, int root)
{
    int V_ectorsation = MST_GRAPH.size(); //--

    vector<int> k(V_ectorsation, 2147483647); //----

    vector<int> parent_of(V_ectorsation, 0); //---

    vector<bool> inMST(V_ectorsation, false); //----

    // Set the key of the root to 0
    k[root] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Insert all vertices into the min-priority queue
    for (int u = 0; u < V_ectorsation; ++u)
    {
        minHeap.push({k[u], u});
    }

    while (!minHeap.empty())
    {
        //
        // obtain  the vertex the min k(key)
        //
        int obtained_u_vertex = minHeap.top().second;
        minHeap.pop();

        inMST[obtained_u_vertex] = true; //maeking here because we need to add to MST

        // Update k vals of adjacent vertices using loop and check
        for (int v = 0; v < V_ectorsation; ++v)
        {
            if (!inMST[v] && MST_GRAPH[obtained_u_vertex][v] < k[v])
            {
                parent_of[v] = obtained_u_vertex;
                k[v] = MST_GRAPH[obtained_u_vertex][v];

                // decrease the key operation (updaye the quue)
                minHeap.push({k[v], v});
            }
        }
    }

    // print out what  the MST is
    for (int i = 1; i < V_ectorsation; ++i)
    {
        cout << parent_of[i] << "\n";
    }
}



//pgs #625 -628
int main()
{
    int V, E;
    cin >> V >> E;

    // reate an adjacency matrix to show it exists i in the graph
    vector<vector<int>> graph(V, vector<int>(V, 2147483647));

    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = graph[v][u] = weight;
    }

    // ROOT WILL BE 0 FOR THIS
    primMST(graph, 0);

    return 0;
}
