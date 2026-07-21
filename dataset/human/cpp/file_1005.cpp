#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int64;

int main(void){
    int64 R,G,B,N;
    cin>>R>>G>>B>>N;
    int64 r,g,b,ans=0;
    for(int64 i=0;i*R<=N;i++){
        for(int64 j=0;i*R+j*G<=N;j++){
            if((N-i*R-j*G)%B==0) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
