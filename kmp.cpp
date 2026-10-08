#include "bits/stdc++.h"
using namespace std;

#ifndef DeBuG
    #define dbg(...)
#endif

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

using ll = long long;
const int MOD = 1e9 + 7, N = 1e5 + 10;

int failure[N];
int KMP(string &str) {
	int cur = 0, mxcur = 0;
	failure[0] = cur;

	for(int i = 1 ; i < (int)str.size() ; i++) {

		while(cur != 0 && str[cur] != str[i]) cur = failure[cur - 1];
		if(str[cur] == str[i]) ++cur;

		failure[i] = cur;
		mxcur = max(mxcur, cur);
	}
	return mxcur;
}


void solve() {
    string p, t; cin >> p >> t;
    string s = p + "$" + t;

    KMP(s);
    for(int i = 0 ; i < (int)s.size() ; i++) {
    	if(failure[i] == (int)p.size()) {
    		cout<<"Match Found\n";
    		return;
    	}
    }

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