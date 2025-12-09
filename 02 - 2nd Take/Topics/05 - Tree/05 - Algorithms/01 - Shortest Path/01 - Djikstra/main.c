#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define V 6
#define INF 999999

typedef int   Vertex;
typedef int*  Distance;
typedef int** DistanceMatrix;
typedef int   Matrix[V][V];

// ----------------------------------------------
// Find vertex with minimum distance
// ----------------------------------------------
Vertex minDistance(Distance dist, bool *visited) {
    int min = INT_MAX;
    Vertex min_index = -1;

    for (Vertex v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// ----------------------------------------------
// Dijkstra Algorithm
// Returns malloc'd distance array
// ----------------------------------------------
Distance dijkstra(Matrix graph, Vertex src) {
    Distance dist = malloc(sizeof(int) * V);
    bool *visited = calloc(V, sizeof(bool));

    for (Vertex v = 0; v < V; v++) {
        dist[v] = INF;
        visited[v] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        Vertex u = minDistance(dist, visited);
        visited[u] = true;

        for (Vertex v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    free(visited);
    return dist;
}

// ----------------------------------------------
// Floyd–Warshall Algorithm
// Returns a malloc’d 2D int** containing shortest paths
// ----------------------------------------------
DistanceMatrix warshall(Matrix graph) {
    // allocate row pointers
    DistanceMatrix dist = malloc(V * sizeof(int*));
    // allocate single contiguous block
    int *data = malloc(V * V * sizeof(int));

    // set row pointers
    for (int i = 0; i < V; i++)
        dist[i] = data + i * V;

    // copy entire graph at once
    memcpy(data, graph, V * V * sizeof(int));

    // Floyd–Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist; // free using free(dist[0]); free(dist);
}

// ----------------------------------------------
// MAIN PROGRAM
// ----------------------------------------------
int main() {
    Matrix graph = {
    {0,   7,   9,   INF, INF, 14},
    {7,   0,   10,  15,  INF, INF},
    {9,   10,  0,   11,  INF, 2 },
    {INF, 15,  11,  0,   6,   INF},
    {INF, INF, INF, 6,   0,   9 },
    {14,  INF, 2,   INF, 9,   0 }
    };

    // Dijkstra from node 0
    Distance shortest = dijkstra(graph, 0);
    printf("Shortest distances from node 0:\n");
    for (int i = 0; i < V; i++)
        printf("Node %d = %d\n", i, shortest[i]);
    free(shortest);

    // Floyd–Warshall all-pairs
    DistanceMatrix allPairs = warshall(graph);
    printf("\nAll-pairs shortest paths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%7d ", allPairs[i][j]);
        printf("\n");
    }

    // free contiguous block and row pointers
    free(allPairs[0]);
    free(allPairs);

    return 0;

}
