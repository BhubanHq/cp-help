
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/* Legendre's Formula
   Returns the exponent of prime p in n!

   Time: O(log_p n)
   Space: O(1)
   Constraints: n >= 0, p >= 2 and p is prime
*/

ll legendre(ll n, ll p) {
    ll ans = 0;

    while(n > 0) {
        n /= p;
        ans += n;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, p;
    cin >> n >> p;

    cout << legendre(n, p) << '\n';

    return 0;
}
