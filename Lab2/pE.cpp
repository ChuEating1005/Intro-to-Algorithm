#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int long long
struct X
{
    int q;
    int r;  
};
int modPow(int x, int y, int k, int p)
{
    X xn;
    X ans;
    xn.q = (x / k) % p;
    xn.r = x % k;
    ans.q = 0;
    ans.r = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ans.q = (((k % p) * ans.q ) % p * xn.q) % p + (ans.q * xn.r) % p + (xn.q * ans.r) % p + (ans.r * xn.r) / k;
            ans.q %= p;
            ans.r = (ans.r * xn.r) % k;
        }
        y = y / 2;
        xn.q = (((k % p) * xn.q) % p  * xn.q) % p + 2 * xn.q * xn.r + (xn.r * xn.r) / k;
        xn.q %= p;
        xn.r = (xn.r * xn.r) % k;
    }
    int result = (ans.q + ans.r / k) % p;
    return result;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int x, y, k, p;
        cin >> x >> y >> k >> p;
        cout << modPow(x,y,k,p) << "\n";
    }
    return 0;
}