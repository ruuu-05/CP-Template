#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N = 1e5 + 5;
const int M = 1e5 + 5; // Size should match maximum possible edges

int n, m;
vector<pair<int, int>> adj[N]; // {neighbor, edge_id}
int tin[N], low[N], timer;
bool is_bridge[M];

/*
 * ==============================================================================
 * BRIDGE FINDING (TARJAN'S / DFS TREE) — NOTES & COMPLEXITY
 * ==============================================================================
 * 
 * WHAT IS IT?
 * Finds all bridges in an undirected graph. A bridge is an edge whose removal 
 * increases the number of connected components (i.e., it's a single point of failure).
 * 
 * TIME COMPLEXITY:
 * - O(N + M): Each node and edge is visited exactly once during the DFS.
 * 
 * SPACE COMPLEXITY:
 * - O(N + M): For storing the adjacency list, tracking arrays (`tin`, `low`), 
 *   and the `is_bridge` flags.
 * 
 * WHEN TO USE:
 * - Problems asking for critical roads/connections that, if blocked, disconnect the graph.
 * - Building a "block-cut tree" or shrinking 2-edge-connected components.
 * ==============================================================================
*/

void find_bridges(int u, int p_edge_id = -1) {
    tin[u] = low[u] = ++timer;
    
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int id = edge.second;
        
        if (id == p_edge_id) continue; // Don't go back to parent via the same edge
        
        if (tin[v]) {
            // Back-edge: v is an ancestor of u
            low[u] = min(low[u], tin[v]);
        } else {
            // Tree-edge: v is a child in DFS tree
            find_bridges(v, id);
            low[u] = min(low[u], low[v]);
            
            // The Bridge Condition
            if (low[v] > tin[u]) {
                is_bridge[id] = true;
            }
        }
    }
}


// ==============================================================================
// HOW TO USE IN MAIN
// ==============================================================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Store neighbor and the unique edge index (0-indexed or 1-indexed)
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    // Run DFS for all components (in case the graph is disconnected)
    timer = 0;
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) {
            find_bridges(i);
        }
    }

    // Optional: Print out which edges are bridges
    cout << "Bridges found (edge IDs):" << nl;
    for (int i = 0; i < m; i++) {
        if (is_bridge[i]) {
            cout << "Edge " << i << " is a bridge\n";
        }
    }

    return 0;
}
