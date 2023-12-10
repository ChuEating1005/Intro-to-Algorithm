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
    if(n > m) swap(n, m);
    for(int i = 1; i <= n; i++)
    {
        ans += min(k/i, m) - max(1LL, m + 1 - (n * m - k + 1)/(n - i + 1)) + 1;
    }
    cout << ans << "\n";
}
