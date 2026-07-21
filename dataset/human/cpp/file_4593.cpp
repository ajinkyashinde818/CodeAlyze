#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n>=10)
        cout<<m<<endl;
    else
        cout<<m+100*(10-n)<<endl;
    return 0;
}
