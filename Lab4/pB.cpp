#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define IOS cin.tie(0);ios::sync_with_stdio(0);
#define int long long
#define mod (int)(1e9 + 7)
using namespace std;
struct Item{
    int c, v;
};
int knapsack(int N, int V_t, map<int, int> &items){
    vector<int> dp(V_t + 1, 0);

    for (auto &item : items) {
        for (int V = item.first; V <= V_t; V++) {
            dp[V] = max(dp[V], dp[V - item.first] + item.second);
        }
    }

    return dp[V_t];
}
signed main(){
    IOS;

    int t; cin >> t;

    while(t--){
        int N, V; cin >> N >> V;

        vector<Item> ori_items(N);
        map<int, int> items;
        for (int i = 0; i < N; i++) cin >> ori_items[i].c;
        for (int i = 0; i < N; i++) cin >> ori_items[i].v;
        for (int i = 0; i < N; i++) items[ori_items[i].c] = max(items[ori_items[i].c], ori_items[i].v);

        cout << knapsack(N, V, items) << "\n";
    }
    return 0;
}
