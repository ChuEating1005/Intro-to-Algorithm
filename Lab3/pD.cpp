#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
bool compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b)
{
    if(a.F < b.F)
        return true;
    else
        return false;
}
signed main()
{
    //fast IO
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> u(n+1), v(m+1), A(n * m + 1);
    vector< vector<int> > ans(n, vector<int>(m));
    vector<pair<int, pair<int, int> > > rank(n * m + 1);
    for(int i = 0; i < n; i++)
        cin >> u[i];
    for(int i = 0; i < m; i++)
        cin >> v[i];
    for(int i = 0; i < n * m; i++) 
        cin >> A[i];

    sort(u.begin(), u.begin() + n);
    sort(A.begin(), A.begin() + n * m);
    sort(v.begin(), v.begin() + m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            rank[i * m + j].F = u[i] * v[j];
            rank[i * m + j].S = mp(i,j);
        }
    sort(rank.begin(), rank.begin() + n * m, compare);
    for(int i = 0; i < n * m; i++)
    {
        int x = rank[i].S.F, y = rank[i].S.S;
        ans[x][y] = A[i];
    }
    int cnt = 0;
    vector<int> temp(m, 0);
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++)
            temp[j] += ans[i][j] * u[i];
        
    for(int i = 0; i < m; i++)
        cnt += temp[i] * v[i];
 
    cout << cnt << "\n";
    for(int i = 0; i < n; i++)
        cout << u[i] << " ";
    cout << "\n";
    for(int i = 0; i < m; i++)
        cout << v[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }   
    return 0;
}
