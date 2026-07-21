#include<iostream>
using namespace std;
int main(){
    int R,G,B,N;
    int ans=0;
    cin>>R>>G>>B>>N;
    for(int i=0;i<=N;i++){
        if(i*R>N)break;
        for(int j=0;j<=N;j++){
            if(i*R + j*G>N)break;
            
            if((N- i*R - j*G)%B==0)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
