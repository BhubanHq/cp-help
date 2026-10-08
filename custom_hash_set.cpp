#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
    #define dbg(...)
#endif

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

using ll = long long;
const int MOD = 1e9 + 7, N = 2e5 + 5;



struct HashPair {
    size_t operator()(const pair<ll,ll>& p) const {
        return hash<ll>()(p.first)
             ^ (hash<ll>()(p.second)<<1);
    }
};


void solve() {
 ll x,y;
    cin>>x>>y;

    auto dv1 = find_divisor(x);
    auto dv2 = find_divisor(y);

    ll prod = x*y;

    unordered_set<pair<ll,ll>, HashPair> seen;
    vector<pair<ll,ll>> ans;

    for(ll a:dv1){
        for(ll b:dv2){

            ll f=a*b;
            ll s=prod/f;

            if(f>s) swap(f,s);

            if(!seen.insert({f,s}).second)
                continue;

            ans.push_back({f+x,s+y});

            if(f!=s)
                ans.push_back({s+x,f+y});
        }
    }

    cout<<ans.size()<<"\n";
    for(auto &[u,v]:ans)
        cout<<u<<" "<<v<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin >> T;
    for (int ti = 1; ti <= T; ti++) {
        solve();
    }
}