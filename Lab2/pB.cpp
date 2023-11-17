#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int long long
#define NINF -(1<<9)
struct Node {
    int sum;
    int prefix;
    int suffix;
};

vector<Node> tree(800005);
vector<int> arr(200005,0);

void build(int L, int R, int idx)
{
    if (L == R)
    {
        tree[idx].sum = arr[L];
        tree[idx].prefix = arr[L];
        tree[idx].suffix = arr[L];
        return;
    }
    int mid = (L + R) / 2;
    build(L, mid, idx * 2);
    build(mid + 1, R, idx * 2 + 1);
    tree[idx].sum = tree[idx * 2].sum + tree[idx * 2 + 1].sum;
    tree[idx].prefix = max(
        tree[idx * 2].prefix,
        tree[idx * 2].sum + tree[idx * 2 + 1].prefix
    );
    tree[idx].suffix = max(
        tree[idx * 2 + 1].suffix,
        tree[idx * 2 + 1].sum + tree[idx * 2].suffix
    );

}
Node query(int ql, int qr, int l, int r, int idx)
{
    Node result;
    result.sum = result.prefix = result.suffix = NINF;
    int m = (l + r) / 2; 
    if (l > qr || r < ql)
        return result;
    if (ql <= l && r <= qr)
        return tree[idx];
    else if(qr <= m)
    {
        return query(ql, qr, l, m, idx * 2);
    }
    else if(ql > m)
    {
        return query(ql, qr, m + 1, r, idx * 2 + 1);
    }
    Node left = query(ql, qr, l, m, idx * 2);
    Node right = query(ql, qr, m + 1, r, idx * 2 + 1);
    result.sum = left.sum + right.sum;
    result.prefix = max(
        left.prefix, 
        left.sum + right.prefix
    );
    result.suffix = max(
        right.suffix,
        right.sum + left.suffix
    );
    return result;
}
void update(int tar, int value, int l, int r, int idx)
{
    int m = (l + r) / 2; 
    if(l == r)
    {
        tree[idx].sum = tree[idx].prefix = tree[idx].suffix = value;
        return;
    }
    if(tar <= m)
    {
        update(tar, value, l, m, idx * 2);
    }
    else
        update(tar, value, m + 1, r, idx * 2 + 1);

    tree[idx].sum = tree[idx * 2].sum + tree[idx * 2 + 1].sum;
    tree[idx].prefix = max(
        tree[idx * 2].prefix,
        tree[idx * 2].sum + tree[idx * 2 + 1].prefix
    );
    tree[idx].suffix = max(
        tree[idx * 2 + 1].suffix,
        tree[idx * 2 + 1].sum + tree[idx * 2].suffix
    );
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(1, n, 1);
    for(int i = 0; i < q; i++)
    {
        int op, ql, qr;
        cin >> op >> ql >> qr;
        if(op == 1)
            update(ql, qr, 1, n, 1);
        else if(op == 2)
            cout << query(ql, qr, 1, n, 1).sum << "\n";
        else if(op == 3)
            cout << max(0LL, query(ql, qr, 1, n, 1).prefix) << "\n";
        else
            cout << max(0LL, query(ql, qr, 1, n, 1).suffix) << "\n";
    }
    return 0;
}