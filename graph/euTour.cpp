#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N = 1e5 + 5;

int n;
vector<int> adj[N];
int tin[N], tout[N]; // Entry and exit times
int timer_euler = 0;
int flat[N];        // Values mapped to a 1D array order

/*
 * ==============================================================================
 * EULER TOUR TECHNIQUE (ETT) — NOTES & WHEN TO USE
 * ==============================================================================
 * 
 * WHAT IS IT?
 * It flattens a 2D tree structure into a 1D linear array using a DFS traversal.
 * 
 * WHEN TO USE:
 * - Subtree Queries & Updates: When a problem asks to update all nodes in the 
 *   subtree of u or query the sum/max of a subtree. 
 * - Because of ETT, all nodes in the subtree of `u` occupy a contiguous range 
 *   in the flat array: from `tin[u]` to `tout[u]`. 
 * - This turns a tree problem into a standard range query problem that you can 
 *   solve using a Segment Tree or Fenwick Tree in O(log N) time!
 * 
 * COMPLEXITY:
 * - Flattening (DFS): O(V)
 * - Range Query/Update (with Segment Tree / Fenwick): O(log V) per operation.
 * ==============================================================================
*/

void euler_tour(int u, int p) {
    tin[u] = ++timer_euler;
    flat[timer_euler] = u; // Optional: keeps track of which node is at this flat index
    
    for (int v : adj[u]) {
        if (v != p) {
            euler_tour(v, u);
        }
    }
    tout[u] = timer_euler; // All nodes in u's subtree fall in the range [tin[u], tout[u]]
}


// ==============================================================================
// HOW TO USE IN MAIN
// ==============================================================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1. Run Euler Tour (usually starting from root node 1, parent = 0)
    timer_euler = 0;
    euler_tour(1, 0);

    // 2. Now every node `u` has a contiguous subtree range: [tin[u], tout[u]]
    // Example: To query or update the subtree of node `x`:
    // int left_bound = tin[x];
    // int right_bound = tout[x];
    // Pass `[left_bound, right_bound]` into your Segment Tree or Fenwick Tree!

    return 0;
}
