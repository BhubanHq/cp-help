#include<bits/stdc++.h> 
#define endl "\n"
#define ll long long
#define Faster  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
 
using namespace std;
ll mod = 1e9+7;
const int N = 1e5 + 9;
int arr[N];
int t[N * 4];

void build(int node, int b, int e){
   if(b==e){
      t[node] = arr[b];
      return;
   }
   int l = 2*node, r = 2*node +1;
   int mid = (b+e)/2;

   build(l, b, mid);
   build(r, mid+1, e);
   t[node] = t[l] + t[r];        // change this

}


int query(int node, int b, int e, int i, int j){
   if(b > j or e < i) return 0;       // return appropriate value
   if(b >= i && e<= j){
      return t[node];
   }

   int l= 2*node, r = 2*node + 1;
   int mid = (e+b)/2;
   return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);  // change this
}

void upd(int node, int b, int e, int i, int x){
   if(e < i or i < b) return;
   if(b==e && b==i){
      t[node] = x;            // update
      return;
   }

   int l = node*2, r = node*2 + 1;
   int mid = (b+e)/2;
   upd(l, b, mid, i, x);
   upd(r, mid+1, e, i, x);
   t[node] = t[l] + t[r];         // change this
}


void solve(){
   int n;
   cin >> n;

   for(int i=1 ; i<= n ; i++){
      cin >> arr[i];
   }

   build(1,1,n);                // building segment tree
   cout<<t[1]<<endl;
   cout<<query(1,1,n,2,4)<<endl;
   upd(1,1,n,3,10);             // assign 10 to the index 3 arr[3] = 10
   cout<<query(1,1,n,2,4)<<endl;  // range query on the segment
   cout<<t[1]<<endl;
}

 
int main()
{
    Faster;
    int t=1;
    //cin >> t;
    while(t--)
    {
       solve();
      
     }
    return 0;
 
}