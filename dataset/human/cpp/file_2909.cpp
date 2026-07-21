#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int main(){
    int n,m=0,min=INT_MAX;
    long sum=0L;
    bool f0=false;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        if(!a[i])f0=true;
        if(a[i]<0)m++,a[i]*=-1;
        sum+=a[i];
        if(a[i]<min)min=a[i];
    }
    if(f0){cout<<sum<<endl;return 0;}
    if(m%2)cout<<sum-min*2<<endl;
    else cout<<sum<<endl;
    return 0;
}
