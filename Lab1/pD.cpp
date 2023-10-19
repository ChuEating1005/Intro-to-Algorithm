#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define int long long
#define mp make_pair

void q_sort(vector<int> &v, vector<int> &idx, int l, int r)
{
    vector<int> newV(v.size());
    int max = r;
    for(int i = v.size(); i >= 1; i--)
    {
        if(l+1 <= idx[i] && idx[i] <= r+1)
        {
            newV[max] = i;
            max--;
        }
    }
    for(int i = l; i <= r; i++)
    {
        v[i] = newV[i];
    }
    for(int i = 0; i < v.size(); i++)
    {
        idx[v[i]] = i+1;
    }
}

bool check(vector<int> &v, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(v[i] != i + 1) 
            return false;
    }
    return true;
}

void print(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
signed main() 
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), idx(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        a[b[i]-1] = i + 1;
        idx[i + 1] = b[i];
    }
    int ans = -1;
    for(int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        q_sort(a, idx, l, r);
        if(ans == -1 && check(a, n)) ans = i;
    }
    cout << ans << "\n";
    return 0;
}