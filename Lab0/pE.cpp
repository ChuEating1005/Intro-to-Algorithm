#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    deque< pair<int,int> > dq; //first: num of people, second: num of masks he/she has
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int op, x;
        cin >> op >> x;
        if(op == 1)
        {
            for(auto it = dq.begin(); it != dq.end(); it++) it->second += x;
        }
        else if(op == 2)
        {
            for(auto it = dq.begin(); it != dq.end(); it++)
            {
                if(it->first > x) 
                {
                    it->first -= x;
                    break;
                }
                else if (it->first == x)
                {
                    dq.pop_front();
                    break;
                }
                else
                {
                    x -= it->first;
                    dq.pop_front();
                    continue;
                }
            }
        }
        else
        {
            if(!dq.empty() && dq.back().second == 0)
                dq.back().first += x;
            else
                dq.push_back(make_pair(x,0));
        }
        if(dq.empty()) cout << "0\n";
        else
            cout << dq[0].second << "\n";
    }
    return 0;
}