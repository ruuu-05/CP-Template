 * // Binary Splitting (Binary Decomposition)
// Converts a multiset into O(log freq) weighted items.
// Returns the grouped values for 0/1 Knapsack.
     
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

/*
 * ==============================================================================
 * BINARY SPLITTING / BINARY DECOMPOSITION (BOUNDED KNAPSACK) — NOTES
 * ==============================================================================
 *
 * WHAT IS IT?
 * It converts items with a frequency/count into $O(\log \text{freq})$ weighted groups. 
 * 
 * WHEN TO USE:
 * - Bounded Knapsack Problem: When you are given items that can be chosen multiple 
 *   times (up to a limit `c`), but iterating through them one-by-one causes Time Limit 
 *   Exceeded (TLE).
 * - Why it works: Any number up to `c` can be formed by summing a unique combination 
 *   of powers of two ($1, 2, 4, 8, \dots$). This trick transforms a **Bounded Knapsack** 
 *   into a standard **0/1 Knapsack** problem instantly.
 * 
 * TIME COMPLEXITY:
 * - $O(\max(\text{value}) + \sum \log(\text{freq}))$: Drastically reduces the number of items 
 *   from $\sum \text{freq}$ down to $\sum \log(\text{freq})$.
 * 
 * SPACE COMPLEXITY:
 * - $O(\text{sum of generated groups})$
 * ==============================================================================
*/

vector<int> binarySplit(const vector<int>& a) {
    if (a.empty()) return {};

    int mx = *max_element(a.begin(), a.end());
    vector<int> freq(mx + 1, 0);

    for (int x : a)
        freq[x]++;

    vector<int> groups;

    for (int value = 0; value <= mx; value++) {
        int cnt = freq[value];

        for (int take = 1; take <= cnt; take <<= 1) {
            groups.push_back(take * value);
            cnt -= take;
        }

        if (cnt)
            groups.push_back(cnt * value);
    }

    return groups;
}


// ==============================================================================
// HOW TO USE IN MAIN
// ==============================================================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Example: Suppose you have multiple identical items. 
    // Instead of looping through all occurrences, binarySplit compresses them 
    // into power-of-two groupings for your 0/1 Knapsack DP transition.
    
    vector<int> items = {3, 3, 3, 3, 3}; // Item value 3 appears 5 times (count = 5)
    
    vector<int> optimized_items = binarySplit(items);

    cout << "Optimized items for 0/1 Knapsack: ";
    for (int x : optimized_items) {
        cout << x << " "; // Will output groups like 3, 6, 6 (representing 1*3, 2*3, 2*3)
    }
    cout << nl;

    return 0;
}
