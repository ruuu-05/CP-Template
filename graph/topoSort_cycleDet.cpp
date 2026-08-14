#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N = 1e5 + 5;

int n, m;
vector<int> adj[N];
int in_degree[N];
int vis[N]; // 0: unvisited, 1: visiting, 2: visited

/*
 * ==============================================================================
 * TOPOLOGICAL SORTING — NOTES & COMPLEXITY
 * ==============================================================================
 *  *    - Time Complexity: O(V + E)
 *       - Space Complexity: O(V + E)
 * 1. KAHN'S ALGORITHM (BFS)
 *    - Use when: You just need a valid topological order and cycle detection.
 * 
 * 2. LEXICOGRAPHICAL TOPOLOGICAL SORT
 *    - Time Complexity: O(V + E log V) due to priority_queue
 *    - Use when: The problem requires the lexicographically smallest ordering.
 * 
 * 3. DFS TOPOLOGICAL SORT
 *    - Space Complexity: O(V + E) (plus recursion stack depth O(V))
 *    - Use when: You prefer DFS post-order traversal or need simultaneous cycle checks via back-edges.
 * 
 * ==============================================================================
*/


// 1. Kahn's Algorithm (BFS)
vector<int> topo_kahn() {
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) deg[i] = in_degree[i];

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (order.size() != n) return {}; // Cycle detected (IMPOSSIBLE)
    return order;
}


// 2. Lexicographically Smallest Topological Sort
vector<int> topo_lexical() {
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) deg[i] = in_degree[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) pq.push(i);
    }

    vector<int> order;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (--deg[v] == 0) {
                pq.push(v);
            }
        }
    }

    if (order.size() != n) return {}; // Cycle detected
    return order;
}


// 3. DFS Topological Sort + Cycle Detection
bool cyclic = false;
vector<int> dfs_order;

void dfs(int u) {
    vis[u] = 1; // visiting
    for (int v : adj[u]) {
        if (vis[v] == 1) {
            cyclic = true; // Back-edge found -> Cycle!
            return;
        } else if (vis[v] == 0) {
            dfs(v);
        }
    }
    vis[u] = 2; // visited
    dfs_order.push_back(u);
}

vector<int> topo_dfs() {
    cyclic = false;
    dfs_order.clear();
    for (int i = 1; i <= n; i++) vis[i] = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            dfs(i);
            if (cyclic) return {};
        }
    }
    reverse(all(dfs_order));
    return dfs_order;
}


// ==============================================================================
// HOW TO USE IN MAIN
// ==============================================================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. Read vertices and edges
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++; // Important: track in-degrees for Kahn / Lexical
    }

    // 2. Run your preferred topological sort method
    // Example using Kahn's algorithm:
    vector<int> ans = topo_kahn();

    // Or use lexicographical: vector<int> ans = topo_lexical();
    // Or use DFS: vector<int> ans = topo_dfs();

    // 3. Check for cycle / output result
    if (ans.empty()) {
        cout << "IMPOSSIBLE" << nl; // Graph has a cycle
    } else {
        for (int x : ans) {
            cout << x << " ";
        }
        cout << nl;
    }

    return 0;
}
