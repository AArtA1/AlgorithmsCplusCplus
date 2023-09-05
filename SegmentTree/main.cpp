#include <iostream>

#define MAXN (int)10e5

// http://e-maxx.ru/algo/segment_tree


int n, t[4*MAXN];


// Segment Tree
// Finds sum/min on the segment

// Build
// Time Complexity: O(n)
// build(arr,1,0,arr.size()-1)
// left node - 2*v
// right node - 2*v+1
void build (int a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}


// Sum
// Time Complexity: O(nlogn)
// sum(1,0,arr.size()-1, ld
int sum (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, std::min(r,tm))
           + sum (v*2+1, tm+1, tr, std::max(l,tm+1), r);
}


// Update
// Time Complexity: O(nlogn)
// update(1,0,arr.size()-1, ld
// also can be implemented as a non-recursive
void update (int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {

}
