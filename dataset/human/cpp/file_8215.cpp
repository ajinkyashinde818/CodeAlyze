#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long a[n],sum[n+1]={},all;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    } 

    all=sum[n];
    long long mi=1e15;

    for(int i=1;i<n;i++){
        mi=(long long)min(mi,abs(2*sum[i]-all));
    }
    cout<<mi;

}
