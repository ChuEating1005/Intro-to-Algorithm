#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define int long long
using namespace std;
struct Job
{
    int s, f, w;
};
vector<Job> jobs(500001);
bool cmp(Job a, Job b)
{
    return a.f < b.f;
}
int BST_floor(int x, int n)
{
    int l = 0, r = n - 1;
    while(l < r)
    {
        //special case
        if(r - l == 1)
        {
            if(jobs[r].f < jobs[x].s)
                return r;
            else if(jobs[l].f < jobs[x].s)
                return l;
            else
                return -1;
        }
        int mid = (l + r) / 2;
        if(jobs[mid].f < jobs[x].s)
            l = mid;
        else
            r = mid - 1;
    }
    if(jobs[l].f < jobs[x].s)
        return l;
    else
        return -1;
}
int weightActivitySelection(int n)
{
    int dp[n + 1];
    vector<int> q(n);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        q[i] = BST_floor(i,n);
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[q[i - 1] + 1] + jobs[i - 1].w);
    }
    return dp[n];
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> jobs[i].s >> jobs[i].f >> jobs[i].w;
    }
    sort(jobs.begin(), jobs.begin() + n, cmp);
    cout << weightActivitySelection(n) << "\n";
    return 0;
}
