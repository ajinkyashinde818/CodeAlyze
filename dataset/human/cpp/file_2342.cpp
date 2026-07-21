#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b){
    int c=min(a,b), d=max(a,b);
    if(d%c==0)return c;
    return GCD(c, d%c);}

int main(){
    int n;cin>>n;
    vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];
    int mini=100000000;for(int i=0;i<n;i++)mini=min(mini,abs(a[i]));
    int minus=0;for(int i=0;i<n;i++)if(a[i]<0)minus++;
    long long sum=0;for(int i=0;i<n;i++)sum+=abs(a[i]);
    if(minus%2==1)sum-=mini+mini;

    cout<<sum<<endl;
    return 0;
}
