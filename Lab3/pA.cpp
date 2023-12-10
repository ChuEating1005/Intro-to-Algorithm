#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
int BST_floor(int x, int l, int r, vector<int> &v)
{
    while(l < r)
    {
        //special case
        if(r - l == 1)
        {
            if(v[r] <= x)
                return r;
            else if(v[l] <= x)
                return l;
            else
                return -1;
        }
        int mid = (l + r) / 2;
        if(v[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    if(v[r] <= x)
        return r;
    else
        return -1;
}
int BST_ceil(int x, int l, int r, vector<int> &v)
{
    int R = r;
    while(l < r)
    {
        //special case
        if(r - l == 1)
        {
            if(v[R] - v[r] >= x)
                return r;
            else if(v[R] - v[l] >= x)
                return l;
            else
                return -1;
        }
        int mid = (l + r) / 2;
        if(v[R] - v[mid] >= x)
            l = mid;
        else
            r = mid - 1;
    }
    if(v[R] - v[r] >= x)
        return r;
    else
        return -1;
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    vector<int> presum(n+1);
    presum[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v.begin() + 1, v.begin() + n + 1);
    for(int i = 1; i <= n; i++)
        presum[i] = presum[i-1] + v[i];
    while(q--)
    {
        int x, y;
        stack<pair<int, int> > st;
        cin >> x >> y;
        int prev = 0, ans = 0, eat;
        while(x < y)
        {
            if(x >= v[prev+1] && prev < n)
            {
                eat = BST_floor(x, prev + 1, n, v);
                st.push(mp(prev, eat - 1));
                x += v[eat];
                prev = eat;
                ans++;
            }
            else
            {
                while(!st.empty())
                {
                    int l = st.top().F, r = st.top().S;
                    st.pop();
                    if(x + presum[r] - presum[l] >= y)
                    {
                        eat = BST_ceil(y - x, l, r, presum);
                        if(eat == -1) 
                            break;
                        x += presum[r] - presum[eat];
                        ans += r - eat;
                    }
                    else if(prev != n && x + presum[r] - presum[l] >= v[prev + 1])
                    {
                        eat = BST_ceil(v[prev + 1] - x, l, r, presum);
                        st.push(mp(l, eat));
                        x += presum[r] - presum[eat] + v[prev + 1];
                        ans += r - eat + 1;
                        prev = prev + 1;
                        break;
                    }   
                    else
                    {
                        x += presum[r] - presum[l];
                        ans += r - l;
                    }
                }
                if(st.empty() && x < y)
                {
                    ans = -1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
