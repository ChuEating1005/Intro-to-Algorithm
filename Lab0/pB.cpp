#include<bits/stdc++.h>
using namespace std;
void output(vector<int> arr, int l)
{
    for(int i = 0; i < l; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int test_cases, op, l, num;
    cin >> test_cases;
    for(int i = 0; i < test_cases; i++)
    {
        cin >> op >> l;
        vector<int> arr, brr, crr;
            if(op == 1)
            {
                //std::sort
                for(int j = 0; j < l; j++)
                {
                    cin >> num;
                    arr.push_back(num);
                }
                sort(arr.begin(), arr.end());
                output(arr, l);
            }
            else if(op == 2)
            {
                //std::reverse
                for(int j = 0; j < l; j++)
                {
                    cin >> num;
                    arr.push_back(num);
                }
                reverse(arr.begin(), arr.end());
                output(arr, l);
            }
            else if(op == 3)
            {
                //std::unique
                for(int j = 0; j < l; j++)
                {
                    cin >> num;
                    arr.push_back(num);
                }
                auto last = unique(arr.begin(), arr.end());
                arr.erase(last, arr.end());
                for(const auto& j : arr)
                    cout << j << " ";
                cout << endl;
            }
            else if(op == 4)
            {
                //std::partial_sum
                for(int j = 0; j < l; j++)
                {
                    cin >> num;
                    arr.push_back(num);
                }
                vector<int> sum(l);
                partial_sum(arr.begin(), arr.end(), sum.begin());
                output(sum, l);
            }
            else if(op == 5)
            {
                //std::min_element, std::max_element
                for(int j = 0; j < l; j++)
                {
                    cin >> num;
                    arr.push_back(num);
                }
                auto min = min_element(arr.begin(), arr.end());
                int min_index = distance(arr.begin(), min);
                reverse(arr.begin(), arr.end());
                auto max = max_element(arr.begin(), arr.end());
                int max_index = l - distance(arr.begin(), max) - 1;
                cout << min_index << " " << max_index << endl;
            }
            else if(op == 6)
            {
                //std::next_permutation, std::prev_permutation
                vector<char> str;
                for(int j = 0; j < l; j++) str.push_back('a' + j);
                reverse(str.begin(), str.end());
                do
                {
                    for(int j = 0; j < l; j++)
                        cout << str[j];
                    cout << " ";
                } while(prev_permutation(str.begin(), str.end()));
                cout << endl;
            }
            else if(op == 7)
            {
                //std::merge
                vector<int> mer(l*2);
                for(int j = 0; j < l; j++)
                {
                    cin >> num;
                    arr.push_back(num);
                }
                for(int j = 0; j < l; j++)
                {
                    cin >> num;
                    brr.push_back(num);
                }
                merge(arr.begin(), arr.end(), brr.begin(), brr.end(), mer.begin());
                sort(mer.begin(), mer.end());
                output(mer, 2*l);
            }
            else if(op == 8)
            {
                //std::set, std::lower_bound, std::upper_bound
                set<int> s;
                for(int j = 0; j < l; ++j) {
                    int tmp; cin >> tmp;
                    s.emplace(tmp);
                }
                for(int j = 0; j < l; ++j) {
                    int tmp; cin >> tmp;
                    auto it = s.upper_bound(tmp);
                    int ans = 0;
                    if(it != s.end())
                        ans = *it;
                    cout << ans << " \n"[j == l-1];
                }
            }
            else if(op == 9)
            {
                //std::map
                map<int, int> count_map;
                arr.resize(l);
                for(int j = 0; j < l; j++)
                {
                    cin >> arr[j];
                    count_map[arr[j]]++;
                }
                for(int j = 0; j < l; j++)
                    cout << count_map[arr[j]] << " ";
                cout << "\n";
            }
            else if(op == 10)
            {
                //std::priority_queue
                priority_queue<int, vector<int>, greater<int> > pq;
                for(int j = 0; j < l; j++)
                {
                    cin >> num;
                    arr.push_back(num);
                }
                for(int j = 0; j < l; ++j)
                {
                    if(arr[j])
                        pq.push(arr[j]);
                    else
                    {
                        if(!pq.empty())
                        {
                            cout << pq.top() << " ";
                            pq.pop();
                        }
                        else
                            pq.push(0);
                    }
                }
                cout << endl;
            }   

    }
}
// 10
// 1 5
// 4 8 7 6 3
// 2 5
// 48 76 34 87 63
// 3 10
// 2 4 4 2 5 5 5 5 55 1
// 4 5
// 4 8 7 6 3
// 5 10
// 4 8 7 6 3 4 8 7 6 3
// 6 3
// 7 5
// 3 4 6 7 8
// 0 2 5 6 9
// 8 5
// 4 8 7 6 3
// 3 1 4 7 9
// 9 10
// 2 7 1 8 2 8 1 8 2 8
// 10 10
// 3 0 0 7 2 0 7 0 0 0