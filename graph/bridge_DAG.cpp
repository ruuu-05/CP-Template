#include <iostream>
#include <bits/stdc++.h>  
 
using namespace std;

const int  N = 1e5 ;// NODES
const int M = 1E5 ; //EDGES
/**
 * Bridge Finding (Tarjan's/DFS Tree)
 * Time Complexity: O(N + M) - Each node and edge is visited once.
 * Space Complexity: O(N + M) - To store the adjacency list and tracking arrays.
 */

vector<pair<int, int>> adj[N]; // {neighbor, edge_id} - Edge ID is vital for multi-edges
int tin[N], low[N], timer;
bool is_bridge[M]; // M is the number of edges

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

// In main or solve():
// timer = 0;
// for(int i = 1; i <= n; i++) if(!tin[i]) find_bridges(i);