#include<iostream>
using namespace std;
int main(){
    int R,G,B,N;
    cin>>R>>G>>B>>N;
    int ans=0;
    for(int i=0;i<=N/R;++i){
        for(int j=0;j<=N/G;++j){
            int tmp=R*i+G*j;
            if(N-tmp>=0){
                if((N-tmp)%B==0){
                    ans+=1;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
