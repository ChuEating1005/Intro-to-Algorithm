#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define int long long
vector< pair< pair<int,int>, int> > v;
bool cmp(pair< pair<int,int>, int> p1, pair< pair<int,int>, int> p2)
{
    if(p1.F.F == p2.F.F)
    {
        return p1.F.S > p2.F.S;
    }
    return p1.F.F < p2.F.F;
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.pb(make_pair(make_pair(a, b), i));
    }
    sort(v.begin(), v.end(), cmp);
    int ans[n], min_R = v[n-1].F.S;
    memset(ans, 0, sizeof(ans));
    for(int i = n-2; i >= 0; i--)
    {
        if(v[i].F.S >= min_R) ans[v[i].S] = 1;
        min_R = min(min_R, v[i].F.S);
    }
    int ans2[n], max_R = v[0].F.S;
    memset(ans2, 0, sizeof(ans2));
    for(int i = 1; i < n; i++)
    {
        if(v[i].F.S <= max_R) ans2[v[i].S] = 1;
        max_R = max(max_R, v[i].F.S);
    }
    for(int i = 0; i < n-1; i++)
    {
        if(v[i].F.F == v[i+1].F.F && v[i].F.S == v[i+1].F.S)
        {
            ans[v[i].S] = ans[v[i+1].S] = 1;
            ans2[v[i].S] = ans2[v[i+1].S] = 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << ans2[i] << " ";
    }
    return 0;
}