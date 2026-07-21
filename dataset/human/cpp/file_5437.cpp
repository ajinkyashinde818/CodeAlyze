// ~/Remember,remember the 6th of March

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-8;
const ll MOD = 1000000007;
const int N = 100000 + 7;

int main()
{
    int n,r;
    cin>>n>>r;
    if(n<10){
        r+=100*(10-n);
    }
    cout<<r<<endl;
    return 0;
}
