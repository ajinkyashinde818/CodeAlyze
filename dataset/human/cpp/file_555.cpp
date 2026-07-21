#include<iostream>
using namespace std;
int main(){
    int r,g,b,n,ans=0;
    cin>>r>>g>>b>>n;
    for(int i=0;i*r<=n;i++){
        for(int j=0;j*g<=n;j++){
            if(n<(r*i+g*j))continue;
            if((n-(r*i+g*j))==0||(n-(r*i+g*j))%b==0)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
