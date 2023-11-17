#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define int long long
using namespace std;
void divide(vector< vector<int> > &vec, int size, int start, int x, int y)
{
    if(size == 1)
    {
        vec[x][y] = start;
        vec[x][y+1] = start+1;
        vec[x+1][y] = start+2;
        vec[x+1][y+1] = start+3;
    }
    else
    {
        int top_left = start;
        int top_right = start + ( 1<<( 2 * size - 2 ) );
        int bottom_left = start + ( 1<<( 2 * size - 2 ) ) * 2;
        int bottom_right = start + ( 1<<( 2 * size - 2 ) ) * 3;
        divide(vec, size-1, top_left, x, y);
        divide(vec, size-1, top_right, x, y + ( 1<<(size-1) ));
        divide(vec, size-1, bottom_left, x + (1<<(size-1)) , y);
        divide(vec, size-1, bottom_right, x + (1<<(size-1)), y + ( 1<<(size-1)));
    }
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    if(n == 0)
        cout << "1\n";
    else
    {
        vector< vector<int> > vec(1<<n, vector<int>(1<<n));
        divide(vec, n, 1, 0, 0);
        for(int i = 0; i < 1<<n; i++) 
        {
            for(int j = 0; j < 1<<n; j++)
            {
                cout << vec[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}