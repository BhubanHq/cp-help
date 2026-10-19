
/* Smallest Prime Factor (SPF)
   Time: O(N log log N)
   Space: O(N)
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int spf[N];

void precompute() {
    iota(spf, spf + N, 0);

    // Mark even numbers
    for(int i = 4; i < N; i += 2)
        spf[i] = 2;

    // Process odd primes
    for(int i = 3; 1LL * i * i < N; i += 2) {
        if(spf[i] != i) continue;

        for(int j = i * i; j < N; j += 2 * i) {
            if(spf[j] == j)
                spf[j] = i;
        }
    }
}

// Prime factors with multiplicity
vector<int> factorize(int x) {
    vector<int> factors;

    while(x > 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }

    return factors;
}
