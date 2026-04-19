#include <bits/stdc++.h>
using namespace std;

const int nmax = 10000;

int phi[nmax];
bool mark[nmax];

/// O(n log log n)

void sieve(){
    for(int i = 1; i<nmax; i++)
        phi[i] = i;

    for(int i = 2; i<nmax; i++){
        if(mark[i]) continue;

        for(int j = i; j<nmax; j+=i){
            phi[j] = phi[j] - phi[j]/i;
            mark[j] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();

    for(int i = 1; i<=20; i++){
        cout<<i<<" "<<phi[i]<<endl;
    }




}
