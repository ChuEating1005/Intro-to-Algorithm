#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    double num;
    double f;
    vector<double> tax, income;
    vector<double> range;
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> num >> f;
        tax.push_back(num - 1);
        range.push_back(f);
    }
    sort(tax.begin(), tax.end());
    sort(range.begin(), range.end());
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> num;
        income.push_back(num);
    }
    for(int i = 0; i < m; i++)
    {
        double taxSum = 0.00000;
        auto it = lower_bound(tax.begin(), tax.end(), income[i]);
        int index = distance(tax.begin(), it) - 1;
        for(int j = 1; j <= index; j++)
        {
            taxSum += (tax[j] - tax[j-1]) * range[j - 1];
        }
        taxSum += (income[i] - tax[index]) * range[index];
        cout << fixed << setprecision(15) << taxSum << endl;
    }
}