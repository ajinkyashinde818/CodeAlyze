#include <iostream>

using namespace std;
int main(void){
    long long N,T,S,ans,F,Z,m,M;
    cin>>N;
    M=1000000000;
    m=-1000000000;
    T=0;
    S=0;
    long long A[N];
    F=0;
    Z=0;
    int j;
    
    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]<0){
            F=F+1;
            T=T+A[i];
            if(m<A[i]){
                m=A[i];
                
            }
        }else if(A[i]==0){
            Z=Z+1;
        }else{
            S=S+A[i];
            if(M>A[i]){
                M=A[i];
            }
        }
    
      
    }
    if(F%2==0){
        ans=S-T;
    }else if(Z>0){
        ans=S-T;
    }else{
        m=m*(-1);
        ans=S-T-min(M,m)*2;
    }
    
    cout<<ans<<endl;
    return 0;
    
}
