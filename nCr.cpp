#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
    #define dbg(...)
#endif

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

using ll = long long;
const int MOD = 998244353, N = 2e5 + 5;

ll modpow(ll base, ll exp) {
    ll ans = 1;
    base %= MOD;

    while (exp >= 1) {
        if (exp & 1)
            ans = (ans * base) % MOD;

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return ans;
}

ll modInv(ll n) {
    return modpow(n, MOD - 2);
}

ll ncr(ll n, ll r) {
    ll factN = 1;

    for (ll i = 1; i <= n; i++)
        factN = (factN * i) % MOD;

    ll den = 1;

    for (ll i = 1; i <= r; i++)
        den = (den * i) % MOD;

    for (ll i = 1; i <= n - r; i++)
        den = (den * i) % MOD;

    return (factN * modInv(den)) % MOD;
}