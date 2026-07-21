#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> cnta(n+1, 0);
    vector<int> cntb(n+1, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnta[a[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        cntb[b[i]]++;
    }
    for(int i = 0; i <= n; i++)
    {
        if(cnta[i] + cntb[i] > n)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cnta[i] += cnta[i-1];
        cntb[i] += cntb[i-1];
    }
    cout << "Yes" << endl;
    int x = 0;
    for(int i = 1; i <= n; i++)
    {
        x = max(x, cnta[i] - cntb[i-1]);
    }
    for(int i = 0; i < n; i++)
    {
        cout << b[(i-x+n)%n] << " ";
    }
    cout << endl;
}
