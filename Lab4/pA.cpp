#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define IOS cin.tie(0);ios::sync_with_stdio(0);
#define int long long
#define mod (int)(1e9 + 7)
using namespace std;
void grouping(int N, vector<vector<int> > &a){
    vector<int> dp(1 << N, 0);
    vector<vector<int> > group(1 << N, vector<int>(N + 1, 0));
    // Runing Time: O(N*2 * 2^n)
    for (int mask = 1; mask < (1 << N); mask++){
        int cnt = 0;
        group[mask][N] = 1;
        for (int i = 0; i < N; i++){
            if (mask & (1 << i)){
                cnt++;
                group[mask][i] = 1;
                for (int j = i + 1; j < N; j++){
                    if(mask & (1 << j)){
                        dp[mask] = (dp[mask] + a[i][j]);
                    }
                }
            }
        }
        if (cnt <= 1){ 
            dp[mask] = -1;
            continue;
        }
    }

    // Runing Time: O(N * 3^N)
    for (int mask = 1; mask < (1 << N); mask++){
        if (dp[mask] == -1) continue;

        for(int submask = mask; submask > 0; submask = (submask - 1) & mask){
            if (dp[submask] == -1 || dp[submask ^ mask] == -1) continue;
            
            int new_sum = dp[submask] + dp[submask ^ mask];
            if (new_sum < dp[mask])
            {
                dp[mask] = new_sum;
                group[mask] = group[submask ^ mask];
                for (int i = 0; i < N; i++){
                    if(submask & (1 << i)){
                        group[mask][i] = group[submask ^ mask][N] + group[submask][i];
                    }
                }
                group[mask][N] = group[submask ^ mask][N] + group[submask][N];
                
            }
        }
    }

    cout << dp[(1 << N) - 1] << "\n";
    for(int i = 0; i < N; i++) cout << group[(1 << N) - 1][i] << " ";
}
signed main(){
    IOS;

    int N; cin >> N;

    vector< vector<int> > a(N, vector<int>(N));
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> a[i][j];

    grouping(N, a);
    return 0;
}
