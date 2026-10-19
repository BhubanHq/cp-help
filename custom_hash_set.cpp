
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/* Custom Hash (splitmix64)
   Average: O(1) insert, find, erase
   Worst case: O(n)
   Supports integers and pairs.
*/

struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    static uint64_t seed() {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now()
                .time_since_epoch().count();

        return FIXED_RANDOM;
    }

    size_t operator()(uint64_t x) const {
        return splitmix64(x + seed());
    }

    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        uint64_t h1 = splitmix64(
            uint64_t(p.first) + seed()
        );
        uint64_t h2 = splitmix64(
            uint64_t(p.second) + seed()
        );

        return splitmix64(h1 ^ (h2 + 0x9e3779b97f4a7c15ULL
                            + (h1 << 6) + (h1 >> 2)));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Integer keys
    unordered_set<ll, CustomHash> st;
    unordered_map<ll, int, CustomHash> mp;

    // Pair keys
    unordered_set<pair<ll, ll>, CustomHash> pairs;
    unordered_map<pair<ll, ll>, int, CustomHash> freq;

    st.insert(10);
    mp[20] = 5;

    pairs.insert({2, 3});
    freq[{2, 3}]++;

    return 0;
}
