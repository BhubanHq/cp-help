struct segTree{
    vector<int> tree;
 
    segTree(int n){
        tree.resize(4*(n+5));
        build(1, 1, n);
    }
 
    void build(int node, int b, int e){
       if(b==e){
          tree[node] = INF;
          return;
        }
    int l = 2*node, r = 2*node +1;
    int mid = (b+e)/2;
 
    build(l, b, mid);
    build(r, mid+1, e);
    tree[node] = min(tree[l], tree[r]);       // change this
    return;
    }
 
 
    void upd(int node, int b, int e, int i, int x){
       if(e < i or i < b) return;
       if(b==e && b==i){
       tree[node] = x;            // update
       return;
     }
 
      int l = node*2, r = node*2 + 1;
      int mid = (b+e)/2;
      upd(l, b, mid, i, x);
      upd(r, mid+1, e, i, x);
      tree[node] = min(tree[l], tree [r]);
      return;         // change this
    }
 
 
    int query(int node, int b, int e, int i, int j){
       if(b > j or e < i) return INF;       // return appropriate value
       if(b >= i && e<= j){
        return tree[node];
      }
 
     int l= 2*node, r = 2*node + 1;
     int mid = (e+b)/2;
     return min(query(l, b, mid, i, j) , query(r, mid + 1, e, i, j));  // change this
    }
};