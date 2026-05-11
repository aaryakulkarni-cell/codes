#include <bits/stdc++.h>
using namespace std;

#define V 5

// Find vertex with minimum distance
int minDistance(int dist[], bool visited[]) {

    int min = INT_MAX, min_index;

    for(int i = 0; i < V; i++) {

        if(visited[i] == false && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int graph[V][V], int src) {

    int dist[V];
    bool visited[V];

    // Initialize
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    // Main loop
    for(int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, visited);

        visited[u] = true;

        // Update distances
        for(int v = 0; v < V; v++) {

            if(!visited[v] &&
               graph[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    cout << "Vertex\tDistance from Source\n";

    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {

    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    dijkstra(graph, 0);

    return 0;
}