#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 2e5+7;
long long int ar[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
     //   scanf("%d" , &ar[i]);
        cin>>ar[i];
    }
    for(int i = 1 ; i < n ; i++){
        ar[i] += ar[i-1];
        //ŝcout<<ar[i]<<endl;
    }
    long long int ans = 1e18;
    for(int i = 0 ; i < n-1 ; i++){
        long long int p = ar[n-1]-ar[i];
        long long int re = abs(p-ar[i]);
        ans = min(ans , re);
    }
    cout<<ans<<endl;
    return 0;
}
