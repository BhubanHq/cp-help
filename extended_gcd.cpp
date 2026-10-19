
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/* Extended Euclidean Algorithm
   Finds x, y such that:
   a*x + b*y = gcd(a, b)

   Time: O(log(min(|a|, |b|)))
   Space: O(log(min(|a|, |b|)))
*/

ll extendedGCD(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = (a >= 0 ? 1 : -1);
        y = 0;
        return abs(a);
    }

    ll x1, y1;
    ll g = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, x, y;
    cin >> a >> b;

    ll g = extendedGCD(a, b, x, y);

    cout << "GCD: " << g << '\n';
    cout << "x: " << x << ", y: " << y << '\n';

    return 0;
}
