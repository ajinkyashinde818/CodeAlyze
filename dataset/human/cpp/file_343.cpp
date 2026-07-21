#include <iostream>
using namespace std;
int main(void){
    long long R,G,B,N,i,j,k,ans;
    cin>>R>>G>>B>>N;
    ans=0;
    for(i=0;i*R<N+1;i++){
        for(j=0;i*R+j*G<N+1;j++){
            if((N-i*R-j*G)%B==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
