#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define ll long long
#define all(v) v.begin(), v.end()

/*
 * ==============================================================================
 * BINARY SEARCH TEMPLATES — NOTES & WHEN TO USE
 * ==============================================================================
 * 
 * 1. BINARY SEARCH ON ANSWER (PREDICATE FUNCTION)
 *    - Use when: The problem asks for the "minimum possible maximum" or "maximum 
 *      possible minimum", and the condition is monotonic (if X works, X+1 works too, or vice versa).
 *    - Time Complexity: O(log(Range) * Time(check))
 * 
 * 2. BINARY SEARCH ON RANGE (ARRAY / VECTOR)
 *    - Use when: Finding an element or position in a sorted array. 
 *      (Tip: Prefer `std::lower_bound` and `std::upper_bound` built-ins when possible).
 * ==============================================================================
*/

// ==============================================================================
// 1. BINARY SEARCH ON ANSWER TEMPLATE
// ==============================================================================

// Example check function: Returns true if `mid` is a valid answer
bool check(ll mid) {
    // Implement your problem-specific validation logic here
    return true; 
}

void solve_bs_on_answer() {
    ll l = 0, r = 1e18; // Set bounds based on the problem constraints
    ll ans = -1;

    while (l <= r) {
        ll mid = l + (r - l) / 2; // Prevents overflow

        if (check(mid)) {
            ans = mid;     // Record valid answer
            r = mid - 1;   // Try to find a smaller valid answer (for minimization)
            // l = mid + 1; // Use this instead if you are trying to maximize the answer
        } else {
            l = mid + 1;   // Need a larger value
            // r = mid - 1; // Use this if checking failed on the upper side
        }
    }

    cout << ans << nl;
}


// ==============================================================================
// 2. BINARY SEARCH ON RANGE / SORTED ARRAY TEMPLATE
// ==============================================================================

void solve_bs_on_array() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(all(a)); // Array must be sorted

    ll target = 42;

    // Method A: Using C++ STL (Recommended)
    auto it = lower_bound(all(a), target); // First element >= target
    auto ut = upper_bound(all(a), target); // First element > target
    
    if (it != a.end() && *it == target) {
        int index = it - a.begin();
        cout << "Found at index: " << index << nl;
    }

    // Method B: Manual Binary Search (Finding exact match or lower bound)
    int l = 0, r = n - 1;
    int idx = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid] >= target) {
            idx = mid;   // Potential lower bound
            r = mid - 1; // Look for a tighter match on the left
        } else {
            l = mid + 1; // Look on the right
        }
    }

    if (idx != -1 && a[idx] == target) {
        cout << "Found target via manual search at index " << idx << nl;
    }
}
