// Binary Splitting (Binary Decomposition)
// Converts a multiset into O(log freq) weighted items.
// Returns the grouped values for 0/1 Knapsack.

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
