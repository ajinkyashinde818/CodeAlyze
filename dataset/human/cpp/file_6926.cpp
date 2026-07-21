#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll a[n],b[n];

    for(int i=0 ; i<n; i++)
        cin >> a[i];
    for(int i=0 ; i<n; i++)
        cin >> b[i];

    reverse(b,b+n);
    int p=0,q=n-1;

    for(int i=0 ; i<n ; i++)
    {
        if(a[i] == b[i] && p<q)
        {
            if(b[p]!=a[i] && b[i]!=a[p])
            {
                swap(b[p],b[i]);
                p++;
            }
            else if(b[q]!=a[i] && b[i]!=a[q])
            {
                 swap(b[q],b[i]);
                 q--;
            }
        }
    }
    bool f=0;
    for(int i=0 ;i<n ; i++)
    {
        if(a[i] == b[i])
        {
            f=1;
            break;
        }
    }
    if(f)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        for(int i=0 ; i<n ; i++)
            cout << b[i] << " ";
        cout << "\n";
    }


    return 0;
}
