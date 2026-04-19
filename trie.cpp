#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define MAXN 50000000
#define LL_INF (1LL << 62)
#define PI acos(-1)
using pii = pair<ll, ll>;

const ll inf = 1e15;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
const int N = 1e6 + 9;

///Trie/Radix Tree
struct trie
{
    bool endmark; //boolean variable to mark end of number
    trie *arr[26]; //10length array of trie nodes for 0-9
    int count;
    //constructor
    trie()
    {
        endmark = 0;
        count = 0;
        for(int i=0; i < 26; i++)
        {
            arr[i] = NULL;
        }
    }
} * root; //globally declaring variable of the struct

void insert(string s)
{
    int n = s.size();
    //for( ; s[n]; n++) {} //size()

    trie *curr = root;
    for(int i=0; i<n; i++)
    {
        int x = s[i] - 'a';
        if(curr->arr[x]==NULL) curr->arr[x] = new trie();
        curr = curr->arr[x];
        curr->count++;
    }
  //  cout<<curr->count<<endl;
    curr->endmark = 1;
}

void del(trie* node)
{
    for(int i=0; i<26; i++)
    {
        if(node->arr[i]!=NULL) //recursive del!
            del(node->arr[i]);
    }
    delete(node);
}


ll isPrefix(trie *node)
{
    for(int i=0; i < 26; i++)
    {
        if(node->arr[i]!=NULL)
        {
            if(node->endmark) return 1;
            if(isPrefix(node->arr[i])) return 1;
        }
    }
    return 0;
}

int search(trie *node, int step){
   int ans = (step * node->count);
   for(int i = 0 ; i < 26 ; i++){
      if(node->arr[i] != NULL){
         ans = max(ans, search(node->arr[i], step + 1));
      }
   }
  return ans;
}

void solve(int cs){
   root = new trie();
   int n;
   cin >> n;
   while(n--){
     string str;
     cin >> str;
     insert(str);
   }
   cout<<"Case "<<cs<<": ";
   cout<<search(root, 0)<<endl;
   del(root);
 
}
   
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    for(int i=1; i<=T; i++) {
        solve(i);
    }
    return 0;   
}   