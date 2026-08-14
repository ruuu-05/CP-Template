#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nl "\n"
#define ll long long
#define all(v) v.begin(), v.end()

/*
 * ==============================================================================
 * STRING HASHING (POLYNOMIAL ROLLING HASH) — NOTES & TEMPLATE
 * ==============================================================================
 * 
 * 1. WHAT IS IT?
 *    A technique to convert a string (or its substrings) into a numeric hash value 
 *    so that any two substrings can be compared in O(1) time after O(N) preprocessing.
 * 
 * 2. WHEN TO USE:
 *    - Substring search / Pattern matching (Rabin-Karp algorithm).
 *    - Finding palindromes, repeating substrings, or longest common substrings.
 *    - Speeding up string comparisons when direct comparison ($O(length)$) is too slow.
 * 
 * 3. CORE FORMULA:
 *    hash(s) = (s[0]*p^0 + s[1]*p^1 + ... + s[n-1]*p^(n-1)) % MOD
 *    - Base (`p`): A prime number larger than the alphabet size (e.g., 31 for lowercase, 53 for mixed case).
 *    - Modulo (`MOD`): A large prime (e.g., 1e9 + 7 or 1e9 + 9) to minimize collisions.
 * 
 * 4. TIME & SPACE COMPLEXITY:
 *    - Preprocessing: O(N)
 *    - Query (Get Hash of any substring): O(1)
 *    - Space: O(N)
 * ==============================================================================
*/

struct StringHash {
    int n;
    ll MOD = 1e9 + 7;
    ll p = 31;
    vector<ll> hash_val, power, inv_power;

    ll binpow(ll a, ll b) {
        ll res = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    ll modInverse(ll n) {
        return binpow(n, MOD - 2);
    }

    StringHash(const string& s) {
        n = s.length();
        hash_val.assign(n + 1, 0);
        power.assign(n + 1, 1);
        inv_power.assign(n + 1, 1);

        ll p_inverse = modInverse(p);

        for (int i = 0; i < n; i++) {
            power[i + 1] = (power[i] * p) % MOD;
            inv_power[i + 1] = (inv_power[i] * p_inverse) % MOD;
            hash_val[i + 1] = (hash_val[i] + (s[i] - 'a' + 1) * power[i]) % MOD;
        }
    }

    // Get hash of substring s[l...r] (0-indexed) in O(1) time
    ll get_hash(int l, int r) {
        ll val1 = hash_val[r + 1];
        ll val2 = hash_val[l];
        ll res = (val1 - val2 + MOD) % MOD;
        res = (res * inv_power[l]) % MOD;
        return res;
    }
};

// ==============================================================================
// HOW TO USE IN MAIN
// ==============================================================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "abracadabra";
    StringHash sh(s);

    // Compare substring s[0...2] ("abr") with s[7...9] ("abr")
    if (sh.get_hash(0, 2) == sh.get_hash(7, 9)) {
        cout << "Substrings match!" << nl;
    } else {
        cout << "Substrings do not match!" << nl;
    }

    return 0;
}
