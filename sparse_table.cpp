#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size();
int log2_floor(int x) {
    return x ? __builtin_clzll(1) - __builtin_clzll(x) : -1;
}
 
struct SparseTable {
    vector<vector<int>> table;
    int n, k;
 
    SparseTable() {};
 
    SparseTable(vector<int> &v) {
        n = sz(v) - 1;
        k = log2_floor(n) + 1;
        table = vector<vector<int>>(k + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            table[0][i] = v[i];
        }
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j + (1LL << i) - 1 <= n; j++) {
                table[i][j] = max(table[i - 1][j], table[i - 1][j + (1LL << (i - 1))]);
            }
        }
    };
 
    int query(int l, int r) {
        if (l > r) return 0;
        int lg = log2_floor(r - l + 1);
        return max(table[lg][l], table[lg][r - (1LL << lg) + 1]);
    }
 
    ~SparseTable() { table.clear(); }
} table;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v(n + 1);
  for(int i = 1; i <= n; i++) cin >> v[i];
  table = SparseTable(v);
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    ++l;
    ++r;
    cout << table.query(l, r) << '\n';
  }
  return 0;
}