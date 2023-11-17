#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int long long
vector<int> b(2000005), in(2000005), post(2000005), idx(2000005);
int ans = 0, n;
void construct(int l, int r, int root, int skip)
{
    int idx_root = idx[root];
    if(l == r)
    {
        ans += b[in[l]-1];
        return;
    }
    else
    {
        if(idx_root != l)construct(l, idx_root - 1, post[idx_root - skip - 1], skip);
        if(idx_root != r)construct(idx_root + 1, r, post[r - skip - 1], skip+1);
    }
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> b[i]; 
    for(int i = 0; i < n; i++) 
    {
        cin >> in[i]; 
        idx[ in[i] ] = i;
    }
    for(int i = 0; i < n; i++) 
        cin >> post[i]; 
    construct(0, n-1, post[n-1], 0);
    cout << post[n-1] << "\n" << ans;
    return 0;
}