#include "1612.h"
#include <bits/stdc++.h>
using namespace std;
int convex_hull(int L, int k) {
    vector<int> v(L+1,0);
    v[0] = 0;
    v[L-1] = 0;
    int lm = 1e9, rm = -1e9;
    int l = 0, r = L;
    for (int i = 0; i < 32 && l <= r; i++){
        int mid = (lm + rm) / 2;
        auto [x, y] = query(mid);
        v[x] = y;
        if (x > k) 
        {
            r = x - 1;
            rm = mid; 
            continue;
        } 
        else if (x < k) 
        {
            l = x + 1;
            lm = mid;
            continue;
        } 
        else if (x == k)
        {
            return y;
        }
    }
    int x1 = k, x2 = k;
    while(v[x1]==0) x1--;
    while(v[x2]==0) x2++;
    int y = v[x1] + (k - x1) * (v[x2] - v[x1]) / (x2 - x1);
    return y;
}

