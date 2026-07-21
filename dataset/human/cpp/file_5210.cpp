//02-03-2020

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,r;
    cin>>n>>r;

    if(n>=10)
        cout<<r<<"\n";
    else
        cout<<r+(100*(10-n))<<"\n";
    return 0;

}
