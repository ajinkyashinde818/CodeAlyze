#include<iostream>
using namespace std;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;

    int ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int k=n-i*r-j*g;
            if(k>=0&&k%b==0) ans++;
        }
    }
    cout<<ans<<endl;
}
