#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define IOS cin.tie(0);ios::sync_with_stdio(0);
#define int long long
#define mod (int)(1e9 + 7)
using namespace std;

signed main(){
    IOS;

    int t; cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        //int maxl = 0;
        vector<int> dp(n, 0), sum(n, 0);
        for (int i = 0; i < n; i++){
            int maxNum = 0;
            for (int j = i - 1; j >= 0; j--){
                if (a[j] <= a[i] && a[j] > maxNum){
                    //if (maxLen[j] + 1 > maxLen[i])  maxLen[i] = maxLen[j] + 1;
                    dp[i] = (dp[i] + dp[j]) % mod;
                    sum[i] = (sum[i] + sum[j] + a[i] * dp[j]) % mod;
                    maxNum = a[j];
                }
            }
            if (dp[i] == 0) dp[i] = 1;
            if (sum[i] == 0) sum[i] = a[i];
            //maxl = max(maxl, maxLen[i]);
        }

        
        // cout << "\nDebugggg:\nDp:\n";
        // for (int i = 0; i < n; i++) cout << dp[i] << " ";
        // cout << "\nMaxLen:\n";
        // for (int i = 0; i < n; i++) cout << maxLen[i] << " ";
        // cout << "\nSum:\n";
        // for (int i = 0; i < n; i++) cout << sum[i] << " ";
        // cout << "\n\nAns:\n";
        

        int ans_count = 0, ans_sum = 0, maxNum = 0, start = n - 1;
        //while (maxLen[start] != maxl) start--;
        for (int j = start; j >= 0; j--){
            if (a[j] > maxNum){
                ans_count = (ans_count + dp[j]) % mod;
                ans_sum = (ans_sum + sum[j]) % mod;
                maxNum = a[j];
            }
        }

        cout << ans_count << " " << ans_sum << "\n";
    }

    return 0;
}

// 6
// 5
// 2 3 6 4 6
// 5
// 1 15 8 2 4
// 7
// 5 3 4 1 7 2 6
// 2
// 2 1
// 3
// 15 15 15
// 15
// 1 5 3 2 8 6 4 13 11 9 14 12 10 7 15