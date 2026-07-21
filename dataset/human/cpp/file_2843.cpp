#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,b=0,c=0,a[100000];
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){b=1;}
        if(a[i]<0){c++;}
        a[i]=abs(a[i]);
        }
    sort(a,a+n);
    if(b==0 && c%2==1){
        for(int i=1;i<n;i++){ans+=a[i];}
        ans-=a[0];
    }
    else{
        for(int i=0;i<n;i++){ans+=a[i];}
    }
    cout<<ans<<endl;
}
