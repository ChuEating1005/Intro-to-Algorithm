#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define int long long
#define mp make_pair
bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.F < p2.F;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, w_sum = 0, ans = 0, a;
    cin >> n;
    vector<pair<int,int> > pre(n);
    vector<int> w(n);
    for(int i = 0; i < n; i++)  
    {
        cin >> a;
        if(i > 0) 
            pre[i] = mp(a + pre[i-1].F, i);
        else 
            pre[i] = mp(a, 0);
    }
    for(int i = 0; i < n; i++)  
    {
        cin >> w[i];
        w_sum += w[i];
    }
    vector<pair<int,int> > pre2 = pre;
    sort(pre.begin(), pre.end(), cmp);
    int k = 0, i = -1, index;
    while(k < (w_sum + 1)/2)
    {
        i++;
        index = pre[i].S;
        k += w[index];   
    }
    if(index != n - 1 && k == (w_sum + 1) / 2 && w_sum % 2 == 0)
    {
        if(w[index] > w[index + 1])
            index = pre[i].S;
        else
            index = pre[i+1].S;
    }
    int pre_k = pre2[index].F;
    for(int i = 0; i < n - 1; i++)
    {
        ans += abs(pre_k - pre2[i].F) * w[i];
    }
    cout << ans << "\n";
}


