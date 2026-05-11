#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
int parent[100];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[a] = b;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[100];

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges, edges + E, compare);

    // Initialize parent
    for(int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edges in MST:\n";

    for(int i = 0; i < E; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if(u != v) {
            cout << edges[i].u << " - " << edges[i].v 
                 << " : " << edges[i].weight << endl;

            unionSet(u, v);
        }
    }

    return 0;
}