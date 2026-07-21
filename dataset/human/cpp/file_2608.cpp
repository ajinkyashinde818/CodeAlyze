#include<bits/stdc++.h>
using namespace std;
int main(){long long n,i,s,m;m=0;cin>>n;vector<long long> a(n);for(i=0;i<n;i++){cin>>a[i];if(a[i]<0){m++;a[i]=-a[i];}s+=a[i];}sort(a.begin(), a.end());cout<<s-(m%2?2*a[0]:0)<<endl;}
