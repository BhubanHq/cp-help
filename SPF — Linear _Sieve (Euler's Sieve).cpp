#include<bits/stdc++.h>
using namespace std;

/* Linear Smallest Prime Factor (SPF)
   Time: O(N)
   Space: O(N)
*/

const int N = 2e5 + 5;
int spf[N];
vector<int> primes;

void precompute() {
    spf[1] = 1;

    for(int i = 2; i < N; i++) {
        if(spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for(int p : primes) {
            if(p > spf[i] || 1LL * i * p >= N)
                break;

            spf[i * p] = p;
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
