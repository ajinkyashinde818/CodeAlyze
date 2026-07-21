#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int cnt=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int z=n-(i*r+j*g);
            if(0<=z && z%b==0)cnt++;
        }
    }
    cout<<cnt<<endl;
}
