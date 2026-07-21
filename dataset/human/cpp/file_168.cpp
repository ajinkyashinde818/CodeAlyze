#include <iostream>

int main(){
    int R,G,B,N;
    std::cin>>R>>G>>B>>N;
    int ans=0;
    for(int i=0;i<=N;++i){
        for(int j=0;j<=N;++j){
            if( (N-i*R-G*j)>=0 && (N-i*R-G*j)%B==0) ans+=1;
        }

    }
    std::cout<<ans<<std::endl;


}
