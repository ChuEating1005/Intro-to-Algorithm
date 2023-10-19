#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    vector<pair<int,int> > student;
    queue<pair<int,int> > q;
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        student.push_back(make_pair(a, b));
        q.push(student[i]);
    }
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        cout << p.first << "\n";
        p.second--;
        if(p.second > 0)
            q.push(p);
    }
}