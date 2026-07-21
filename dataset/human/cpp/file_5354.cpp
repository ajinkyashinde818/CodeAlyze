#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int n,r;
    cin>>n>>r;
    if(n>=10) cout<<r<<endl;
    else cout<<r+(10-n)*100<<endl;
    return 0;
}
