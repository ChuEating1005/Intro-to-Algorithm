#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define int long long
using namespace std;
//Define a compare function for priority_queue
class Compare {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            if (a.S > b.S)
                return true;
            else
                return false;
        }
};
signed main()
{
    //fast IO
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    //variable declaration
    priority_queue <pair<int, int>, vector<pair<int, int> >, Compare> pq; //create a min heap
    vector<int> a(n + 2); // a[i] = the rabbitization rating of the i-th person
    vector<pair<int, int> >node(n + 2); // node[i] = (i, a[i]) to store the index and rating of the i-th person
    vector< vector<int> > record; // record[i] = the members of i-th round of battle
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        node[i] = make_pair(i, a[i]);
        pq.push(node[i]);
    }
    int total = 0, round = 0, cnt = 0;
    pair<int, int> temp;
    //special case
    if(k != 2 && n % (k-1) != 1)
    {
        round++;
        vector<int> tempVec;
        int r;
        if(n % (k-1) == 0) 
            r = k-1;
        else 
            r = n % (k-1);
        tempVec.pb(r);
        for(int i = 0; i < r; i++)
        {
            tempVec.pb(pq.top().F);
            cnt += pq.top().S;
            pq.pop();
        }
        temp = make_pair(n + round, cnt);
        pq.push(temp);
        record.pb(tempVec);
        total += cnt;
    }   
    //general case
    while(pq.size() > 1)
    {
        int curSize = pq.size();
        vector<int> tempVec; 
        round++;
        cnt = 0;
        tempVec.pb(k);
        //pop k smallest elements from the heap, and push the sum of them back to the heap
        for(int i = 0; i < k; i++)
        {
            tempVec.pb(pq.top().F);
            cnt += pq.top().S;
            pq.pop();
        }
        temp = make_pair(n + round, cnt);
        pq.push(temp);
        record.pb(tempVec);
        total += cnt;
    }
    cout << total << "\n" << round << "\n";
    for(int i = 0; i < round; i++)
    {
        for(int j = 0; j <= record[i][0]; j++)
        {
            cout << record[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
