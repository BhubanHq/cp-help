
#include <bits/stdc++.h>
using namespace std;

/* Binary Search on Monotonic Predicate
   Time: O(log n) calls to ok()
   Space: O(1)

   First True: F F F T T T
   Last True:  T T T F F F
*/

// First True (minimum valid index)
// If no valid index exists, returns n.
int firstTrue(int n) {
    int l = 0, h = n;  // [l, h)

    while(l < h) {
        int m = l + (h - l) / 2;

        if(ok(m)) h = m;
        else l = m + 1;
    }

    return l;
}

// Last True (maximum valid index)
// If no valid index exists, returns -1.
int lastTrue(int n) {
    int l = -1, h = n;  // (l, h)

    while(h - l > 1) {
        int m = l + (h - l) / 2;

        if(ok(m)) l = m;
        else h = m;
    }

    return l;
}
