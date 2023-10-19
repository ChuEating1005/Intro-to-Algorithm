#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define int long long
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, k, ans = 0, l, r;
    cin >> n >> m >> k;
    int mi = min(n, m);
    int ma = max(n, m);
    n = mi;
    m = ma;
    for(int x = 1; x <= n; x++)
    {
        int c = floor(k/x);
        int d = ceil(m + 1 - (n * m - k + 1)/(n - x + 1));
        r = min(c, m);
        l = max(1LL, d); 
        if(r - l + 1 > 0) ans += r - l + 1;
    }
    cout << ans << "\n";
}