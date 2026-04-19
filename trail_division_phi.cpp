#include <bits/stdc++.h>
using namespace std;


/// 10^15
/// O(sqrt(n)) -> 10^7
long long int phi(long long int n){
    long long int ret = n;

    for(long long int i = 2; i*i <= n; i++){      /// o(sqrt(n)) -> 10^12
        if(n % i == 0){
            /// i is a prime
            /// multiply by (1-1/i)

            ret = ret - ret/i;

            while(n % i == 0){
                n /= i;
            }
        }
    }

    if(n > 1){
        /// n is a prime
        /// multiply by (1-1/n)

        ret = ret - ret/n;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;


    cout<<phi(n)<<endl;

}