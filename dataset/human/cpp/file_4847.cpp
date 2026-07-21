#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
int main()
{
    ll n,r;
    cin>>n>>r;
    if(n>=10)
    cout<<r<<endl;
    else
    cout<<(10-n)*100+r<<endl;;
}
