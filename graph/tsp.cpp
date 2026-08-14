#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define ll long long
#define all(v) v.begin(), v.end()

/*
 * ==============================================================================
 * TRAVELING SALESPERSON PROBLEM (TSP) — BITMASK DP & DIJKSTRA ON STATES NOTES
 * ==============================================================================
 * 
 * 1. WHAT IS IT?
 *    TSP asks for the shortest possible route that visits every city (vertex) 
 *    exactly once and returns to the starting point.
 * 
 * 2. WHEN TO USE:
 *    - Constraints are very small ($N \le 20$). 
 *    - Keywords: "visit every node", "shortest tour", "shortest Hamiltonian cycle".
 *    - Why standard greedy or Dijkstra fails: Because you need to track *which* 
 *      nodes have been visited, leading to exponential states.
 * 
 * 3. HOW IT WORKS (BITMASK DP):
 *    - State representation: `dp(mask, u)` 
 *        - `mask`: An integer bitmask where the $i$-th bit is `1` if city $i$ has 
 *          been visited, and `0` otherwise.
 *        - `u`: The city you are currently standing at.
 *    - Transition: From city `u`, try moving to any unvisited city `v`:
 *        `dp(mask, u) = min over all unvisited v (cost(u, v) + dp(mask | (1 << v), v))`
 *    - Base Case: When `mask == (1 << n) - 1` (all cities visited), return the cost 
 *      to return back to the starting city (usually city 0).
 * 
 * 4. TIME & SPACE COMPLEXITY:
 *    - Time: $O(2^n \cdot n^2)$ for standard complete graphs.
 *    - Space: $O(2^n \cdot n)$ for the memoization table / DP table.
 * ==============================================================================
*/

const int INF = 1e9;
int n;
vector<vector<int>> dist; // Adjacency matrix of edge weights
vector<vector<int>> memo; // DP memoization table: [1 << n][n]

// Bitmask DP function for TSP
int tsp(int mask, int u) {
    // Base Case: If all cities have been visited, return cost to return to start (0)
    if (mask == (1 << n) - 1) {
        return dist[u][0]; // Return to city 0 (or 0 if path doesn't require returning)
    }

    // Return cached result if already computed
    if (memo[mask][u] != -1) {
        return memo[mask][u];
    }

    int ans = INF;

    // Try visiting every other city 'v' that hasn't been visited yet
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) { // If city v is not visited
            ans = min(ans, dist[u][v] + tsp(mask | (1 << v), v));
        }
    }

    return memo[mask][u] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Example setup
    n = 4; // Number of cities
    dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Initialize memo table with -1 (size: 2^n x n)
    memo.assign(1 << n, vector<int>(n, -1));

    // Start tour from city 0, with only city 0 visited initially (mask = 1)
    int min_cost = tsp(1, 0);

    cout << "Minimum TSP Tour Cost: " << min_cost << nl;

    return 0;
}
