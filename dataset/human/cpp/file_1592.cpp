#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    bool flag = false;
    int pos = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
        if(n == sum)
        {
            flag = true;
            pos = i;
            break;
        }
    }
    if(!flag)
    {
        cout << "No" << endl;
        return 0;
    }
    vector<vector<int>> ans(pos+1);
    int i = 1;
    int x = pos;
    int cur = 1;
    while(cur <= n)
    {
        for(int j = 1; j <= x; j++)
        {
            ans[pos-x].push_back(cur);
            ans[pos-x+j].push_back(cur);
            cur++;
        }
        x--;
    }
    cout << "Yes" << endl;
    cout << pos+1 << endl;
    for(int i = 0; i <= pos; i++)
    {
        cout << pos << " ";
        for(int j = 0; j < pos; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
