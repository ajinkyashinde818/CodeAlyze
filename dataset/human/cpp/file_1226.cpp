#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long R,G,B,N;cin>>R>>G>>B>>N;
    long long ans=0;
    for(long long i=0;i*R<=N;i++){
        for(long long j=0;j*G+i*R<=N;j++){
            if((N-(i*R+j*G))%B==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
