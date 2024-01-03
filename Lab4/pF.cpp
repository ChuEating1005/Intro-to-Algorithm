#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define IOS cin.tie(0);ios::sync_with_stdio(0);
#define int long long
#define mod (int)(1e9 + 7)
using namespace std;

int increase(int n, int i, int gap){
    if (i + gap >= n) return -1;
    else return i + gap;
}

int decrease(int n, int i, int gap){
    if (i - gap < 0) return -1;
    else return i - gap;
}

bool have_edge(vector<vector<int> > &adj, int i, int j, int gap){
    if (adj[i][j] == 1) return true;
    else if (gcd(i + 1, j + 1) == gap) return true;
    else return false;
}

signed main(){
    IOS;

    int n, m, p;
    cin >> n >> m >> p;

    vector<vector<int> > adj(n, vector<int>(n, 0));
    int x, y;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x - 1][y - 1] = 1;
        adj[y - 1][x - 1] = 1;
    }
    
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int u = 0; u < n; u++) dp[0][u] = 1;
    for (int d = 0; d < n - 1; d++){
        for (int u = 0; u < n; u++){
            for (int d_ = d + 1; d_ < n; d_++){
                int v1 = increase(n, u, d_);
                int v2 = decrease(n, u, d_);
                if (v1 != -1 && have_edge(adj, u, v1, d_)) 
                    dp[d_][v1] = (dp[d_][v1] + dp[d][u]) % p;                
                if (v2 != -1 && v2 != v1 && have_edge(adj, u, v2, d_)) 
                    dp[d_][v2] = (dp[d_][v2] + dp[d][u]) % p;
            }
        }
    }

    int ans = 0;
    for (int d = 1; d < n; d++) for (int u = 0; u < n; u++) ans = (ans + dp[d][u]) % p;
    cout << ans << "\n";
    return 0;
}
