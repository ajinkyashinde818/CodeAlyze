#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m=0,s=1000000000,a,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a<0){
            m++;
        }
        if(s>abs(a))
            s=abs(a);
        ans+=abs(a);
    }
    if(m%2==0){
        cout<<ans<<endl;
    }
    else{
        cout<<ans-s*2<<endl;
    }
    return(0);
}
