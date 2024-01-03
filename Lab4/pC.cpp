#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define IOS cin.tie(0);ios::sync_with_stdio(0);
#define int long long
#define mod (int)(1e9 + 7)
using namespace std;
void LCS(int N, vector<int> &a, vector<int> &b){
    vector<vector<int> > dp(N+1, vector<int>(N+1, 0));

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (a[i - 1] != b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    int cnt = dp[N][N], i = N, j = N;
    vector<int> lus_a(cnt);
    vector<int> lus_b(cnt);
    while (cnt > 0){
        if (dp[i][j] == dp[i - 1][j]){
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1]){
            j--;
        }
        else{
            lus_a[--cnt] = a[i - 1];
            lus_b[cnt] = b[j - 1];
            i--;
            j--;
        }
    }

    cout << dp[N][N] << "\n";
    for (int i = 0; i < dp[N][N]; i++) cout << lus_a[i] << " ";
    cout << "\n";
    for (int i = 0; i < dp[N][N]; i++) cout << lus_b[i] << " ";
    cout << "\n";
}
signed main(){
    IOS;

    int t; cin >> t;

    while(t--){
        int N; cin >> N;

        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 0; i < N; i++) cin >> b[i];
    
        LCS(N, a, b);
    }
    return 0;
}
