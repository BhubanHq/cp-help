#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/* Bitmask - Subset Enumeration
   Time: O(n * 2^n)
   Space: O(n)
   Recommended: n <= 20-22
*/

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    ll target;
    cin >> target;

    // Each bit represents whether an element is selected.
    // (1 << n) = 2^n possible subsets.

    for(int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;

        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                sum += a[i];
            }
        }

        if(sum == target) {
            cout << "Found: ";

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i))
                    cout << a[i] << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
