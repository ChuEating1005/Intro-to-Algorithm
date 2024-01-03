#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define IOS cin.tie(0);ios::sync_with_stdio(0);
#define int long long
#define mod (int)(1e9 + 7)
using namespace std;
struct Edge{
    int u, v, w;
    char c; // B or W
};
struct Vertex{
    int idx;
    int l;
    int max_star;
};
void topological_Sort(int idx, stack<int> &v_sorted, vector<Vertex> &V, vector< vector<Edge> > &adj, vector< bool > &visit){
    visit[idx] = true;
    for (auto &e : adj[idx]){
        if (!visit[e.v]) topological_Sort(e.v, v_sorted, V, adj, visit);
    }
    v_sorted.push(idx);
}
void maxSumpath(vector<Vertex> &V, vector< vector<Edge> > &adj, int idx){
    //cout << "Index: " << idx << ", max_star:" <<V[idx].max_star << "\n";
    if (V[idx].l > V[idx].max_star) return;
    for (auto &e : adj[idx]){
        V[e.v].max_star = max(V[e.v].max_star, V[idx].max_star + e.w);
    }
}
signed main(){
    IOS;

    int n, m; cin >> n >> m;

    vector<Vertex> V(2 * n);
    for (int i = 0; i < n; i++){
        V[2 * i].idx = 2 * i;
        V[2 * i + 1].idx = 2 * i + 1;
        cin >> V[2 * i].l;
        V[2 * i + 1].l = V[2 * i].l;
        V[2 * i].max_star = 0;
        V[2 * i + 1].max_star = 0;
    }

    vector<Edge> E(m);
    vector< vector<Edge> > adj(2 * n); 
    for (int i = 0; i < m; i++){
        cin >> E[i].u >> E[i].v >> E[i].c >> E[i].w ;
        E[i].u--;
        E[i].v--;
        if(E[i].c == 'B'){
            E[i].u = 2 * E[i].u;
            E[i].v = 2 * E[i].v + 1;
            adj[E[i].u].pb(E[i]);
        }
        else{
            E[i].u = 2 * E[i].u + 1;
            E[i].v = 2 * E[i].v;
            adj[E[i].u].pb(E[i]);
        }
    }
    
    vector< bool > visit(2 * n, false);
    stack<int> v_sorted;
    for (int i = 0; i < 2 * n; i++){
        if (!visit[i]) topological_Sort(i, v_sorted, V, adj, visit);
    }

    while (!v_sorted.empty()){
        maxSumpath(V, adj, v_sorted.top());
        v_sorted.pop();
    }
    
    for (int i = 0; i < n; i++){
        cout << max(V[2 * i].max_star, V[2 * i + 1].max_star) << " ";
    }  

    return 0;
}
